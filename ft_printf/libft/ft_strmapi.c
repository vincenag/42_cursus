/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agvincen <agvincen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 13:23:48 by agvincen          #+#    #+#             */
/*   Updated: 2023/05/31 16:26:46 by agvincen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*cad;
	unsigned int	size;
	unsigned int	i;

	if (!s)
		return (ft_strdup(""));
	size = ft_strlen(s);
	cad = malloc((size + 1) * sizeof(char));
	if (!cad)
		return (0);
	i = 0;
	while (s[i])
	{
		cad[i] = (*f)(i, s[i]);
		i++;
	}
	cad[i] = '\0';
	return (cad);
}
