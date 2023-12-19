/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agvincen <agvincen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 10:50:33 by agvincen          #+#    #+#             */
/*   Updated: 2023/12/19 11:26:20 by agvincen         ###   ########.fr       */
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

typedef struct s_table	t_table;
typedef struct s_philo
{
	int				id; //id del filosofo
	pthread_t		thread; //hilo del filosofo
	int				left_fork; //id del tenedor izquierdo
	int				right_fork; //id del tenedor derecho
	uint64_t		last_meal; //tiempo de la ultima comida
	int				x_eaten;  //numero de veces que ha comido
	t_table			*table; 
}				t_philo;
typedef struct s_table
{
    int				nb_philo; //arg: numero de filosofos
    int				time_to_die; //arg: tiempo para morir en milisegundos
    int				time_to_eat; //arg: tiempo para comer en milisegundos
    int				time_to_sleep;  //arg: tiempo para dormir en milisegundos
    int				nb_meals; //arg: numero de comidas maximo por filosofo
    int                x_meals; //numero de comidas totales
    int                isdead; //estado de muerte
    uint64_t		start_time; //tiempo de inicio en milisegundos
    pthread_mutex_t	*forks_mutex; //mutex para los tenedores
    pthread_mutex_t	check_meal_mutex; //mutex para el tiempo de la ultima comida
    pthread_mutex_t	isdead_mutex; //mutex para el estado de muerte
    pthread_mutex_t print_mutex; //mutex para imprimir
}				t_table;

//u_int64_t

//check args functions
long int	ft_atoi(const char *str);
int	ft_check_args(char	**argv);

//Utils functions
uint64_t    ft_get_time(void);
void    ft_usleep(uint64_t time);
void    ft_print(t_philo *philo, char *status);

//Init functions
t_table *ft_init_table(char **argv);
int	ft_init_philos(t_philo *philos, t_table *table);

//Philo functions
int	ft_start_philos(t_table *table, t_philo *philos);

//Philo_check functions
int ft_check_death(t_philo *philo);
int ft_check_meals(t_philo *philo);
void ft_check_status(t_table *table, t_philo *philos);

//Exit functions
void	ft_exit(t_table *table, t_philo *philos);

#endif