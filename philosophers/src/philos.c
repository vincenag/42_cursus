/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philos.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agvincen <agvincen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 15:26:57 by agvincen          #+#    #+#             */
/*   Updated: 2023/12/22 21:43:32 by agvincen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	ft_spaghetti(t_philo *philo)
{
	ft_print(philo, "has taken a fork\n");
	ft_print(philo, "has taken a fork\n");
	ft_print(philo, "is eating\n");
	pthread_mutex_lock(&philo->last_meal_mutex);
	philo->last_meal = ft_get_time();
	philo->x_eaten++;
	pthread_mutex_unlock(&philo->last_meal_mutex);
	pthread_mutex_lock(&philo->table->check_meal_mutex);
	if (philo->x_eaten == philo->table->nb_meals)
		philo->table->x_done++;
	pthread_mutex_unlock(&philo->table->check_meal_mutex);
	ft_usleep(philo->table->time_to_eat);
}

void	ft_eat(t_philo *philo)
{
	if (philo->left_fork > philo->right_fork)
	{
		pthread_mutex_lock(&philo->table->forks_mutex[philo->right_fork]);
		pthread_mutex_lock(&philo->table->forks_mutex[philo->left_fork]);
	}
	else
	{
		pthread_mutex_lock(&philo->table->forks_mutex[philo->left_fork]);
		pthread_mutex_lock(&philo->table->forks_mutex[philo->right_fork]);
	}
	ft_spaghetti(philo);
	pthread_mutex_unlock(&philo->table->forks_mutex[philo->left_fork]);
	pthread_mutex_unlock(&philo->table->forks_mutex[philo->right_fork]);
	ft_print(philo, "is sleeping\n");
	ft_usleep(philo->table->time_to_sleep);
}

void	*ft_routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (philo->id % 2 == 0)
		ft_usleep(philo->table->time_to_eat);
	if (philo->table->nb_philo == 1)
	{
		ft_print(philo, "has taken a fork\n");
		while (1)
			if (ft_check_death(philo))
				break ;
	}
	else
		while (1)
		{
			if (ft_check_death(philo))
				break ;
			if (ft_check_meals(philo))
				break ;
			ft_eat(philo);
			ft_print(philo, "is thinking\n");
		}
	return (NULL);
}

int	ft_start_philos(t_table *table, t_philo *philos)
{
	int	i;

	i = 0;
	table->start_time = ft_get_time();
	while (i < table->nb_philo)
	{
		if (pthread_create(&philos[i].thread, NULL, ft_routine, &philos[i]))
			return (EXIT_FAILURE);
		pthread_mutex_lock(&philos[i].last_meal_mutex);
		philos[i].last_meal = ft_get_time();
		pthread_mutex_unlock(&philos[i].last_meal_mutex);
		i++;
	}
	ft_check_status(table, philos);
	i = 0;
	while (i < table->nb_philo)
	{
		if (pthread_join(philos[i].thread, NULL))
			return (EXIT_FAILURE);
		i++;
	}
	return (EXIT_SUCCESS);
}
