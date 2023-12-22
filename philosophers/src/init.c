/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agvincen <agvincen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 15:09:19 by agvincen          #+#    #+#             */
/*   Updated: 2023/12/22 21:40:42 by agvincen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	ft_init_mutex(t_table *table)
{
	int	i;

	table->forks_mutex = malloc(sizeof(pthread_mutex_t) * table->nb_philo);
	if (!table->forks_mutex)
		return (EXIT_FAILURE);
	i = 0;
	while (i < table->nb_philo)
	{
		if (pthread_mutex_init(&table->forks_mutex[i], NULL))
		{
			free(table->forks_mutex);
			return (EXIT_FAILURE);
		}
		i++;
	}
	if (pthread_mutex_init(&table->print_mutex, NULL)
		|| pthread_mutex_init(&table->check_meal_mutex, NULL)
		|| pthread_mutex_init(&table->isdead_mutex, NULL))
	{
		free(table->forks_mutex);
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

int	check_min_max(t_table *table)
{
	if (table->nb_philo < 1 || table->nb_philo > 200)
		return (EXIT_FAILURE);
	if (table->time_to_die < 60 || table->time_to_eat < 60
		|| table->time_to_sleep < 60)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

void	init_input_args(t_table *table, char **argv)
{
	table->nb_philo = ft_atoi(argv[1]);
	table->time_to_die = ft_atoi(argv[2]);
	table->time_to_eat = ft_atoi(argv[3]);
	table->time_to_sleep = ft_atoi(argv[4]);
	if (argv[5])
		table->nb_meals = ft_atoi(argv[5]);
	else
		table->nb_meals = -1;
}

t_table	*ft_init_table(char **argv)
{
	t_table	*table;

	table = malloc(sizeof(t_table));
	if (!table)
		return (NULL);
	init_input_args(table, argv);
	if (check_min_max(table))
	{
		printf("Error: Arguments out of limits\n");
		free(table);
		return (NULL);
	}
	table->isdead = 0;
	table->x_done = 0;
	if (ft_init_mutex(table))
	{
		free(table);
		return (NULL);
	}
	return (table);
}

int	ft_init_philos(t_philo *philos, t_table *table)
{
	int i;

	i = 0;
	while (i < table->nb_philo)
	{
		philos[i].id = i + 1;
		philos[i].left_fork = i;
		philos[i].right_fork = (i + 1) % table->nb_philo;
		philos[i].last_meal = 0;
		philos[i].x_eaten = 0;
		philos[i].table = table;
		if (pthread_mutex_init(&philos[i].last_meal_mutex, NULL))
		{
			free(philos);
			free(table->forks_mutex);
			free(table);
			return (EXIT_FAILURE);
		}
		i++;
	}
	return (EXIT_SUCCESS);
}
