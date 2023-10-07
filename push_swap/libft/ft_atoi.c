/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agvincen <agvincen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 16:49:13 by agvincen          #+#    #+#             */
/*   Updated: 2023/09/19 16:42:23 by agvincen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long int	ft_atoi(const char *str)
{
	long int	num_base;
	int				i;
	int				np;

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

/* int	main(void)
{
	char	cad[]= " 	32432-3bdb";

	printf("%i\n", ft_atoi(&cad[0]));
	return(0);
} */