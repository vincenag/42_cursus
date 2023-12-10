/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agvincen <agvincen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 10:50:33 by agvincen          #+#    #+#             */
/*   Updated: 2023/12/09 18:58:03 by agvincen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <unistd.h>
# include <stdlib.h>
# include <stdint.h>
# include <string.h>
# include <limits.h>
# include <stdio.h>
# include <sys/time.h>
# include <pthread.h>

typedef struct s_philo
{
	int				id;
	pthread_t		thread;
	int				left_fork;
	int				right_fork;
	uint64_t		last_meal;
	int				x_eat;
	t_table			*table;
	pthread_mutex_t	x_eat_mutex;
}				t_philo;
typedef struct s_table
{
    int				nb_philo;
    int				time_to_die;
    int				time_to_eat;
    int				time_to_sleep;
    int				nb_eat;
    int				philo_eat;
    uint64_t		start_time;
    pthread_mutex_t	*forks;
    pthread_mutex_t	print_mutex;
    t_philo			*philos;
}				t_table;

//u_int64_t

int	ft_check_args(char	**argv);

#endif