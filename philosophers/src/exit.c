/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agvincen <agvincen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 16:24:52 by agvincen          #+#    #+#             */
/*   Updated: 2023/12/22 21:40:34 by agvincen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	ft_exit(t_table *table, t_philo *philos)
{
	int	i;

	i = 0;
	while (i < table->nb_philo)
	{
		pthread_mutex_destroy(&table->forks_mutex[i]);
		pthread_mutex_destroy(&philos[i].last_meal_mutex);
		i++;
	}
	pthread_mutex_destroy(&table->print_mutex);
	pthread_mutex_destroy(&table->isdead_mutex);
	pthread_mutex_destroy(&table->check_meal_mutex);
	free(table->forks_mutex);
	free(philos);
	free(table);
}
