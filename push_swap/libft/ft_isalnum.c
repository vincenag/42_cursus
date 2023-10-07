/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agvincen <agvincen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 17:17:21 by agvincen          #+#    #+#             */
/*   Updated: 2023/05/02 17:10:30 by agvincen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	if (c < '0' || (c < 'A' && c > '9') || (c > 'Z' && c < 'a') || c > 'z')
		return (0);
	return (1);
}

/* int	main(void)
{
	int	c;

	c = ':';
	printf("%d\n", isalnum(c));
	printf("%i\n", ft_isalnum(c));
	return (0);
} */