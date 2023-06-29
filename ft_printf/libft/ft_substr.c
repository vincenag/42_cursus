/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agvincen <agvincen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 15:30:53 by agvincen          #+#    #+#             */
/*   Updated: 2023/05/31 16:27:41 by agvincen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*subs;
	unsigned int	i;

	if ((unsigned int)ft_strlen(s) < start)
		return (ft_strdup(""));
	if ((ft_strlen(s) - start) < len)
		len = ft_strlen(s) - start;
	subs = malloc(sizeof(char) * (len + 1));
	if (!subs)
		return (0);
	i = 0;
	while (i < len)
	{
		subs[i] = s[start + i];
		i++;
	}
	subs[i] = '\0';
	if (subs == 0)
		return (0);
	return (subs);
}

/* int	main(void)
{
	char	cad[]= "juan jose";

	printf("%s\n", ft_substr(&cad[0], 0, 12));
	return (0);
} */