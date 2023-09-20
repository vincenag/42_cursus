/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_path_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agvincen <agvincen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 14:39:47 by agvincen          #+#    #+#             */
/*   Updated: 2023/09/07 15:43:34 by agvincen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

int	check_flood_fill(t_data *game)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < game->rows)
	{
		while (j < game->columns)
		{
			if (!(game->map_copy[i][j] == '1' || game->map_copy[i][j] == '0'
					|| game->map_copy[i][j] == 'X'))
				return (1);
			j++;
		}
		j = 0;
		i++;
	}
	return (0);
}

void	flood_fill(t_data *game, int y, int x)
{
	if (!(x < 1 || y < 1 || x >= game->columns || y > game->rows
			|| game->map_copy[y][x] == '1' || game->map_copy[y][x] == 'X'))
	{
		game->map_copy[y][x] = 'X';
		flood_fill(game, y + 1, x);
		flood_fill(game, y - 1, x);
		flood_fill(game, y, x + 1);
		flood_fill(game, y, x - 1);
	}
}

void	ft_start(t_data *game)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < game->rows)
	{
		while (j < game->columns)
		{
			if (game->map_copy[i][j] == 'P')
			{
				game->y = i;
				game->x = j;
			}
			else if (game->map_copy[i][j] == 'Z')
			{
				game->y_enem = i;
				game->x_enem = j;
			}
			j++;
		}
		j = 0;
		i++;
	}
}

void	valid_path(t_data *game)
{
	ft_start(game);
	flood_fill(game, game->y, game->x);
	if (check_flood_fill(game) == 1)
	{
		ft_putstr_fd("Error!\nNot valid Path found\n", 2);
		ft_exit(game);
	}
}
