/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agvincen <agvincen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 08:55:34 by agvincen          #+#    #+#             */
/*   Updated: 2023/05/31 15:58:17 by agvincen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	size_cad(int num)
{
	int	i;

	i = 0;
	if (num <= 0)
		i = 1;
	while (num != 0)
	{
		i++;
		num = num / 10;
	}
	return (i);
}

static void	ft_complete(int n, int i, int aux, char *cad)
{
	while (aux > i)
	{
		cad[aux - 1] = '0' + (n % 10);
		n = n / 10;
		aux--;
	}
}

char	*ft_itoa(int n)
{
	char		*cad;
	int			i;
	int			aux;

	aux = size_cad(n);
	cad = malloc(sizeof(char) * (aux + 1));
	if (!cad)
		return (0);
	i = 0;
	if (n == -2147483648)
	{
		cad[0] = '-';
		cad[1] = '2';
		n = 147483648;
		i = 2;
	}
	if (n < 0)
	{
		cad[0] = '-';
		i = 1;
		n = -n;
	}
	ft_complete(n, i, aux, cad);
	cad[aux] = '\0';
	return (cad);
}

/* int	main(void)
{
	printf("%s\n", ft_itoa(-2147483648));
	return(0);
} */