/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agvincen <agvincen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 17:30:19 by agvincen          #+#    #+#             */
/*   Updated: 2023/05/02 17:09:11 by agvincen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;

	j = 0;
	i = 0;
	while (src[j])
		j++;
	if (dstsize == 0)
		return (j);
	while (src[i] && i < dstsize - 1)
	{
			dst[i] = src[i];
			i++;
	}
	dst[i] = '\0';
	return (j);
}

/* int	main(void)
{
	int	i;
	char	cad1[] = "hola";
	char	cad2[] = "---";

	i = 0;
	ft_strlcpy(cad2, cad1, sizeof(char)*3);
	while (cad2[i])
	{
		printf("%c", cad2[i]);
		i++;
	}
	return (0);
} */