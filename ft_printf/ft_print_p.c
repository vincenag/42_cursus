/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_p.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agvincen <agvincen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 15:59:55 by agvincen          #+#    #+#             */
/*   Updated: 2023/05/29 17:43:13 by agvincen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_hex(unsigned long np)
{
	char			*hex;
	unsigned long	count;
	char			c;

	hex = "0123456789abcdef";
	count = 0;
	if (np >= 16)
		count += print_hex(np / 16);
	c = hex[np % 16];
	write (1, &c, 1);
	count++;
	return (count);
}

int	ft_print_p(void *ptr)
{
	int	count;

	count = 0;
	count += ft_print_s("0x");
	count += print_hex((unsigned long)ptr);
	return (count);
}

/* int	main(void)
{
	char	cad[]= "1";

	printf("\nResultado: %d\n", ft_print_p(&cad));
	return (0);
} */