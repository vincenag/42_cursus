/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agvincen <agvincen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 16:18:10 by agvincen          #+#    #+#             */
/*   Updated: 2023/12/22 22:42:04 by agvincen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

uint64_t	ft_get_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * (uint64_t)1000) + (time.tv_usec / 1000));
}

void	ft_usleep(uint64_t time)
{
	uint64_t	total_time;

	total_time = ft_get_time() + time;
	while (ft_get_time() < total_time)
		usleep(10);
}

void	ft_print(t_philo *philo, char *status)
{
	pthread_mutex_lock(&philo->table->print_mutex);
	if (ft_check_death(philo))
	{
		pthread_mutex_unlock(&philo->table->print_mutex);
		return ;
	}
	printf("%lu %d %s", ft_get_time() - philo->table->start_time, philo->id,
		status);
	pthread_mutex_unlock(&philo->table->print_mutex);
}
