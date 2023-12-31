/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agvincen <agvincen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 17:37:46 by agvincen          #+#    #+#             */
/*   Updated: 2023/05/02 17:10:13 by agvincen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isprint(int c)
{
	if (c >= 32 && c <= 126)
		return (1);
	return (0);
}

/* int	main(void)
{
	int	c;

	c = ' ';
	printf("%d\n", isprint(c));
	printf("%i\n", ft_isprint(c));
	return (0);
} */