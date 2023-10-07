/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agvincen <agvincen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 15:27:56 by agvincen          #+#    #+#             */
/*   Updated: 2023/05/02 17:10:01 by agvincen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*str;
	size_t			i;

	i = 0;
	str = (unsigned char *)s;
	while (i < n)
	{
		if (str[i] == (unsigned char)c)
			return (&str[i]);
		i++;
	}
	return (NULL);
}

/* int	main(void)
{
	char	cad[]= "hola amigo";
	char	cad2[]= "hola amigo";

	printf("%s\n", ft_memchr(&cad[0], 'a', 5));
	printf("%s", memchr(&cad2[0], 'a', 5));
	return (0);
} */