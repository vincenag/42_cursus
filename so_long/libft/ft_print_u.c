/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_u.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agvincen <agvincen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 15:31:12 by agvincen          #+#    #+#             */
/*   Updated: 2023/09/11 14:35:23 by agvincen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_print_u(unsigned int num)
{
	unsigned int	count;

	count = 0;
	if (num >= 10)
		count += ft_print_u(num / 10);
	count += ft_print_c(num % 10 + '0');
	return (count);
}
