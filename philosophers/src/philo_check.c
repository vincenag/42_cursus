/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agvincen <agvincen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 13:41:04 by agvincen          #+#    #+#             */
/*   Updated: 2023/12/22 22:41:36 by agvincen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	ft_check_death(t_philo *philo)
{
	pthread_mutex_lock(&philo->table->isdead_mutex);
	if (philo->table->isdead == 1)
	{
		pthread_mutex_unlock(&philo->table->isdead_mutex);
		return (1);
	}
	pthread_mutex_unlock(&philo->table->isdead_mutex);
	return (0);
}

int	ft_check_meals(t_philo *philo)
{
	pthread_mutex_lock(&philo->table->check_meal_mutex);
	if (philo->table->nb_meals != -1
		&& philo->x_eaten >= philo->table->nb_meals)
	{
		pthread_mutex_unlock(&philo->table->check_meal_mutex);
		return (1);
	}
	pthread_mutex_unlock(&philo->table->check_meal_mutex);
	return (0);
}
int	print_death(t_table *table, t_philo *philos, int i)
{
	pthread_mutex_lock(&philos[i].last_meal_mutex);
	if (ft_get_time() - philos[i].last_meal > (uint64_t)table->time_to_die)
	{
		pthread_mutex_unlock(&philos[i].last_meal_mutex);
		pthread_mutex_lock(&table->isdead_mutex);
		table->isdead = 1;
		pthread_mutex_unlock(&table->isdead_mutex);
		printf("%lu %d died\n", ft_get_time() - table->start_time,
			philos[i].id);
		return (1) ;
	}
	pthread_mutex_unlock(&philos[i].last_meal_mutex);
	return (0);
}

void	ft_check_status(t_table *table, t_philo *philos)
{
	int	i;

	i = 0;
	while (1)
	{
		pthread_mutex_lock(&table->check_meal_mutex);
		if (table->nb_meals != -1 && table->x_done >= table->nb_philo)
		{
			pthread_mutex_unlock(&table->check_meal_mutex);
			break ;
		}
		pthread_mutex_unlock(&table->check_meal_mutex);
		if (print_death(table, philos, i))
			break ;
		i = (i + 1) % table->nb_philo;
		usleep(100);
	}
}
