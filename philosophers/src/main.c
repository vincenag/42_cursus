/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agvincen <agvincen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 10:49:26 by agvincen          #+#    #+#             */
/*   Updated: 2023/12/22 22:42:47 by agvincen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	main(int argc, char **argv)
{
	t_table	*table;
	t_philo	*philos;

	if (argc < 5 || argc > 6)
	{
		printf("Number of arguments should be 4 or 5\n");
		return (EXIT_FAILURE);
	}
	if (ft_check_args(argv))
		return (EXIT_FAILURE);
	table = ft_init_table(argv);
	if (!table)
		return (EXIT_FAILURE);
	philos = malloc(sizeof(t_philo) * table->nb_philo);
	if (!philos)
		return (EXIT_FAILURE);
	if (ft_init_philos(philos, table))
		return (EXIT_FAILURE);
	if (ft_start_philos(table, philos))
		return (EXIT_FAILURE);
	ft_exit(table, philos);
	return (0);
}
