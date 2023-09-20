/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_x.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agvincen <agvincen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 17:52:12 by agvincen          #+#    #+#             */
/*   Updated: 2023/09/11 14:35:12 by agvincen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_print_x(char data, unsigned long long np)
{
	char				*hex;
	unsigned long long	count;
	char				c;

	count = 0;
	if (np >= 16)
		count += ft_print_x(data, (np / 16));
	if (data == 'x')
		hex = "0123456789abcdef";
	if (data == 'X')
		hex = "0123456789ABCDEF";
	c = hex[np % 16];
	write (1, &c, 1);
	count++;
	return (count);
}
