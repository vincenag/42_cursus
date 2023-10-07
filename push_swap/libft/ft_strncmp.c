/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agvincen <agvincen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 18:02:56 by agvincen          #+#    #+#             */
/*   Updated: 2023/05/02 18:14:39 by agvincen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n && (s1[i] || s2[i]))
	{
		if (s1[i] != s2[i])
			return (((unsigned char *)s1)[i] - ((unsigned char *)s2)[i]);
		i++;
	}
	return (0);
}

/* int	main(void)
{
	char	        s1[] = "test\200";
	char	        s2[] = "test\0";
    unsigned int    n;

    n = 6;
	printf ("%i\n", strncmp (s1, s2, n));
	printf ("%i", ft_strncmp(&s1[0], &s2[0], n));
	return (0);
} */