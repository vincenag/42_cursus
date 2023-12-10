/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agvincen <agvincen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 10:49:26 by agvincen          #+#    #+#             */
/*   Updated: 2023/12/09 18:58:47 by agvincen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

//falta chequear los limites para cada argumento
t_table *ft_init_table(char **argv)
{
	t_table	*table;

	table = NULL;
	table = malloc(sizeof(t_table));
	if (!table)
		return (NULL);
	table->nb_philo = ft_atoi(argv[1]);
	table->time_to_die = ft_atoi(argv[2]);
	table->time_to_eat = ft_atoi(argv[3]);
	table->time_to_sleep = ft_atoi(argv[4]);
	if (argv[5])
		table->nb_eat = ft_atoi(argv[5]);
	else
		table->nb_eat = -1;
	table->forks = malloc(sizeof(pthread_mutex_t) * table->nb_philo);
	if (!table->forks)
		return (NULL);
	table->philos = malloc(sizeof(t_philo) * table->nb_philo);
	if (!table->philos)
		return (NULL);
	return (table);
}

int	ft_init_philos(t_table *table)
{
	int	i;

	i = 0;
	while (i < table->nb_philo)
	{
		table->philos[i].id = i + 1;
		table->philos[i].table = table;
		table->philos[i].x_eat = 0;
		table->philos[i].last_meal = 0;
		table->philos[i].left_fork = i;
		table->philos[i].right_fork = (i + 1) % table->nb_philo;
		if (pthread_mutex_init(&table->forks[i], NULL))
			return (EXIT_FAILURE);
		i++;
	}
	return (EXIT_SUCCESS);
}

int	main(int argc, char **argv)
{
	t_table	*table;

	if (argc < 5 || argc > 6)
	{
		printf ("Number of arguments should be 4 or 5\n");
		return (EXIT_FAILURE);
	}
	if (ft_check_args(argv))
		return (EXIT_FAILURE);
	table = ft_init_table(argv);
	if (!table)
		return (EXIT_FAILURE);
	if (ft_init_philos(table))
		return (EXIT_FAILURE);
	return (0);
}
