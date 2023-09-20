/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_s.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agvincen <agvincen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 16:16:11 by agvincen          #+#    #+#             */
/*   Updated: 2023/09/11 14:35:28 by agvincen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_putstr(char *s)
{
	int	count;
	int	i;

	i = 0;
	count = 0;
	while (s[i])
	{
		count += ft_print_c(s[i]);
		i++;
	}
	return (count);
}

int	ft_print_s(char *string)
{
	int	count;

	if (!string)
	{
		ft_putstr("(null)");
		return (6);
	}
	count = ft_putstr(string);
	return (count);
}
