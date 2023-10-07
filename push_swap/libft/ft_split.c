/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agvincen <agvincen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 17:28:10 by agvincen          #+#    #+#             */
/*   Updated: 2023/05/11 13:17:54 by agvincen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_words(char const *s, char c)
{
	int	i;
	int	aux;
	int	j;

	i = 0;
	j = 0;
	aux = 0;
	while (s[i])
	{
		if (s[i] != c && aux == 0)
		{
			aux = 1;
			j++;
		}
		else if (s[i] == c)
			aux = 0;
		i++;
	}
	return (j);
}

void	free_all(char **result, int index)
{
	while (index-- > 0)
		free(result[index]);
	free(result);
}

static char	**ft_matrix_fill(char **matrix, char const *s, char c, int *index)
{
	int		i;
	int		j;
	int		start;	

	i = 0;
	while (s[i])
	{
		j = 0;
		if (s[i] != c)
		{
			start = i;
			while (s[i] && s[i++] != c)
				j++;
			matrix[*index] = ft_substr(s, start, j);
			if (!matrix[*index])
			{
				free_all(matrix, *index);
				return (NULL);
			}
			*index = *index + 1;
		}
		else
			i++;
	}
	return (matrix);
}

char	**ft_split(char const *s, char c)
{
	int		index;
	char	**split;

	index = 0;
	split = malloc((ft_count_words(s, c) + 1) * sizeof(char *));
	if (!split)
		return (NULL);
	split = ft_matrix_fill(split, s, c, &index);
	if (!split)
		return (NULL);
	split[index] = 0;
	return (split);
}

/* int	main(void)
{
	char	cad[]= "cccolaccccamigoccccolco";
	char	c;

	c = 'c';
	printf("%d", ft_count_words(&cad[0], c));
	return (0);
} */