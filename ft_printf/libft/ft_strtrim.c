/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agvincen <agvincen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 19:43:18 by agvincen          #+#    #+#             */
/*   Updated: 2023/05/31 16:27:32 by agvincen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count1(const char *s1, const char *set)
{
	size_t	len;
	size_t	i;

	len = ft_strlen(s1);
	i = 0;
	while (i < len)
	{
		if (ft_strchr(set, s1[i]) == 0)
			break ;
		i++;
	}
	return (i);
}

static int	count2(const char *s1, const char *set)
{
	size_t	len;
	size_t	i;

	len = ft_strlen(s1);
	i = 0;
	while (i < len)
	{
		if (ft_strchr(set, s1[len - i - 1]) == 0)
			break ;
		i++;
	}
	return (len - i);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		start;
	int		end;
	char	*temp;

	if (s1 == 0)
		return (0);
	if (set == 0)
		return (ft_strdup(s1));
	start = count1(s1, set);
	end = count2(s1, set);
	if (start >= end)
		return (ft_strdup(""));
	temp = (char *)malloc(sizeof(char) * (end - start + 1));
	if (temp == 0)
		return (0);
	ft_strlcpy(temp, s1 + start, end - start + 1);
	return (temp);
}

/* int	main(void)
{
	char	cad1[] = "lorem \n ipsum \t dolor \n sit \t amet";
	char	cad2[] = " ";

	printf("%s\n", ft_strtrim(cad1, cad2));
	return (0);
} */