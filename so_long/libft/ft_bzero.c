/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agvincen <agvincen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 14:16:38 by agvincen          #+#    #+#             */
/*   Updated: 2023/05/02 17:10:41 by agvincen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*str;
	size_t			i;

	str = (unsigned char *)s;
	i = 0;
	while (i < n && n != '0')
	{
		str[i] = 0;
		i++;
	}
}

/* int	main(void)
{
	char	cad[10]="0123456789";

	ft_bzero(cad, sizeof(char)*2);
	for (int i = 0; i < 10; i++)
		printf("%c", cad[i]);
	return (0);
} */
