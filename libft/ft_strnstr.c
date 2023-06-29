/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agvincen <agvincen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 16:33:13 by agvincen          #+#    #+#             */
/*   Updated: 2023/05/02 18:14:35 by agvincen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	n_len;
	char	*h;

	i = 0;
	h = (char *)haystack;
	n_len = ft_strlen(needle);
	if (n_len == 0 || haystack == needle)
		return (h);
	while (h[i] != '\0' && i < len)
	{
		j = 0;
		while (h[i + j] != '\0' && needle[j] != '\0'
			&& h[i + j] == needle[j] && i + j < len)
			j++;
		if (j == n_len)
			return (h + i);
		i++;
	}
	return (0);
}

/* int	main(void)
{
	char	        str1[] = "test";
	char	        str2[] = "wefeftestfewrfewfe";
    size_t    n;

    n = 7;
	printf ("%s\n", ft_strnstr(&str2[0], &str1[0], n));
	return (0);
} */