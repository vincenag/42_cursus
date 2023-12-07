/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agvincen <agvincen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 13:33:43 by agvincen          #+#    #+#             */
/*   Updated: 2023/12/07 13:42:19 by agvincen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

long int	ft_atoi(const char *str)
{
	long int	num_base;
	int			i;
	int			np;

	np = 1;
	i = 0;
	num_base = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '+' || str[i] == '-')
		if (str[i++] == '-')
			np = -1;
	while (str[i] >= '0' && str[i] <= '9')
	{
		num_base = num_base * 10 + (str[i] - '0');
		i++;
	}
	return (np * num_base);
}

int	ft_isnum(char *str)
{
	while (*str)
	{
		if (*str < '0' || *str > '9')
		{
			printf("All characters must be positive digits\n");
			return (EXIT_FAILURE);
		}
		str++;
	}
	return (0);
}

int	ft_check_args(char	**argv)
{
	int		i;
	long	temp;

	i = 1;
	while (argv[i])
	{
		if (ft_isnum(argv[i]))
			return (EXIT_FAILURE);
		temp = ft_atoi (argv[i]);
		if (temp > INT_MAX)
		{
			printf("argument %s is greater than INT MAX\n", argv[i]);
			return (EXIT_FAILURE);
		}
		i++;
	}
	return (0);
}
