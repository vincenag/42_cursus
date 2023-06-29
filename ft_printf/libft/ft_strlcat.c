/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agvincen <agvincen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 15:25:14 by agvincen          #+#    #+#             */
/*   Updated: 2023/05/02 17:09:16 by agvincen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	res;

	i = 0;
	j = 0;
	res = 0;
	while (dest[i])
		i++;
	while (src[res])
		res++;
	if (size <= i)
		res += size;
	else
		res += i;
	while (src[j] && (i + 1) < size)
	{
		dest[i] = src[j];
		j++;
		i++;
	}
	dest[i] = '\0';
	return (res);
}

/* int	main(void)
{
    char			s1[16] = "hola juan";
    char			s2[] = "como estas?";
	size_t	n;

	n = 0;
	printf ("%lu\n", strlcat (s1, s2, n));
	printf ("%i\n", ft_strlcat(&s1[0], &s2[0], n));
	printf ("%s", s1);
	return (0);
}*/