/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agvincen <agvincen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 15:13:41 by agvincen          #+#    #+#             */
/*   Updated: 2023/06/01 15:07:18 by agvincen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_type(const char *data, va_list new_list)
{
	int	count;

	count = 0;
	if (*data == 'c')
		count += ft_print_c(va_arg(new_list, int));
	else if (*data == 's')
		count += ft_print_s(va_arg(new_list, char *));
	else if (*data == 'p')
		count += ft_print_p(va_arg(new_list, void *));
	else if (*data == 'd' || *data == 'i')
		count += ft_print_d(va_arg(new_list, int));
	else if (*data == 'x' || *data == 'X')
		count += ft_print_x(*data, va_arg(new_list, unsigned int));
	else if (*data == 'u')
		count += ft_print_u(va_arg(new_list, int));
	else if (*data == '%')
	{
		write (1, "%", 1);
		count += 1;
	}
	return (count);
}

int	ft_printf(const char *data, ...)
{
	va_list	new_list;
	int		count;

	va_start (new_list, data);
	count = 0;
	while (*data != '\0')
	{
		if (*data != '%')
		{
			write(1, data, 1);
			count = count + 1;
		}
		else
		{
			data++;
			count += ft_type(data, new_list);
		}
		data++;
	}
	va_end(new_list);
	return (count);
}
