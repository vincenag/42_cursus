/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agvincen <agvincen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 17:12:30 by agvincen          #+#    #+#             */
/*   Updated: 2023/05/31 16:26:13 by agvincen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char			*str;
	unsigned int	i;

	i = 0;
	str = (char *)s;
	while (str[i])
	{
		if (str[i] == (char)c)
			return (&str[i]);
		i++;
	}
	if ((char)c == '\0')
		return (&str[i]);
	return (0);
}

/* int	main(void)
{
	char	cad[]= "hola amigo";
	char	cad2[]= "hola amigo";

	printf("%s\n", ft_strchr(&cad[0], '\0'));
	printf("%s", strchr(&cad2[0], '\0'));
	return (0);
} */
