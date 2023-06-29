/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agvincen <agvincen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 14:54:43 by agvincen          #+#    #+#             */
/*   Updated: 2023/05/02 17:09:52 by agvincen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*str1;
	unsigned char	*str2;
	size_t			i;

	str1 = (unsigned char *)src;
	str2 = (unsigned char *)dst;
	if (!str1 && !str2)
		return (0);
	i = 0;
	while (i < n)
	{
		str2[i] = str1[i];
		i++;
	}
	return (dst);
}

/* int	main(void)
{
	char	cad1[] = "hola_loco";

	ft_memcpy(cad1, cad1 + 5, sizeof(char)*4);
	for (int i = 0; i < 10; i++)
		printf("%c", cad1[i]);
	return (0);
} */
