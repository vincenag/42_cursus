/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agvincen <agvincen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 15:35:43 by agvincen          #+#    #+#             */
/*   Updated: 2023/07/31 18:50:26 by agvincen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero_gnl(void *s, size_t n)
{
	unsigned char	*str;
	size_t			i;

	str = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		str[i] = 0;
		i++;
	}
}

void	*ft_calloc_gnl(size_t nmemb, size_t size)
{
	char	*c;

	c = malloc(nmemb * size);
	if (c == NULL)
		return (NULL);
	ft_bzero_gnl(c, nmemb * size);
	return (c);
}

char	*ft_strchr_gnl(char *s, int c)
{
	char			*str;
	unsigned int	i;

	i = 0;
	if (!s)
		return (0);
	str = (char *)s;
	while (str[i])
	{
		if (str[i] == (char)c)
			return (&str[i]);
		i++;
	}
	if ((char)c == str[i])
		return (&str[i]);
	return (NULL);
}

size_t	ft_strlen_gnl( char *s)
{
	size_t	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strjoin_gnl(char *s1, char *s2)
{
	char	*s3;
	size_t	size1;
	size_t	size2;
	size_t	i;
	size_t	j;

	size1 = ft_strlen_gnl(s1);
	size2 = ft_strlen_gnl(s2);
	s3 = ft_calloc_gnl((size1 + size2 +1), sizeof(char));
	if (!s3)
		return (NULL);
	i = 0;
	while (i < size1)
	{
		s3[i] = s1[i];
		i++;
	}
	j = 0;
	while (j < size2)
	{
		s3[i + j] = s2[j];
		j++;
	}
	free(s1);
	return (s3);
}
