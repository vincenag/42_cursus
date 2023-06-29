/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_d.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agvincen <agvincen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 13:16:01 by agvincen          #+#    #+#             */
/*   Updated: 2023/05/31 15:36:15 by agvincen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_d(int num)
{
	int	count;

	count = 0;
	if (num == -2147483648)
	{
		count += ft_print_c('-');
		count += ft_print_c('2');
		num = 147483648;
	}
	if (num < 0)
	{
		count += ft_print_c('-');
		num *= -1;
	}
	if (num >= 0 && num <= 9)
		count += ft_print_c(num + '0');
	else
	{
		count += ft_print_d(num / 10);
		count += ft_print_d(num % 10);
	}
	return (count);
}

/* int	main(void)
{
	ft_print_d(435.2);
	return (0);
} */