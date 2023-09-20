/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agvincen <agvincen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 23:01:00 by agvincen          #+#    #+#             */
/*   Updated: 2023/09/08 17:36:31 by agvincen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	perimeter(t_data *game)
{
	int	i;

	i = 0;
	while (i < game->columns)
	{
		if (game->map[0][i] != '1' || game->map[game->rows - 1][i] != '1')
			return (0);
		i++;
	}
	i = 0;
	while (i < game->rows)
	{
		if (game->map[i][0] != '1' || game->map[i][game->columns - 1] != '1')
			return (0);
		i++;
	}
	return (1);
}

void	check_walls(t_data *game)
{
	if (perimeter(game) == 0)
	{
		ft_putstr_fd("Error!\nMap must be surrounded by walls\n", 2);
		ft_exit(game);
	}
}

void	characters_count(char c, t_data *game)
{
	if (c != '1' && c != '0' && c != 'C' && c != 'P' && c != 'E' && c != '\n')
	{
		ft_putstr_fd("Error!\nNot allowed characters are present\n", 2);
		ft_exit(game);
	}
	if (c == 'C')
		game->collec_num++;
	if (c == 'P')
		game->player_num++;
	if (c == 'E')
		game->exit_num++;
}

void	characters_check(t_data *game)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < game->rows)
	{
		while (j < game->columns)
		{
			characters_count(game->map[i][j], game);
			j++;
		}
		j = 0;
		i++;
	}
	if (game->collec_num < 1 || game->player_num != 1 || game->exit_num != 1)
	{
		ft_putstr_fd("Error!\nMap rules:\n- One E\n- One P\n- One or more C\n", 2);
		ft_exit(game);
	}
}

void	check(t_data *game)
{
	int		i;
	size_t	len;

	i = 1;
	if (!game->map[0])
	{
		ft_putstr_fd("Error!\nMap is empty\n", 2);
		ft_exit(game);
	}
	len = ft_strlen(game->map[0]);
	while (i < game->rows)
	{
		if (ft_strlen(game->map[i]) != len)
		{
			ft_putstr_fd("Error!\nMap must be rectangular\n", 2);
			ft_exit(game);
		}
		i++;
	}
	check_walls(game);
	characters_check(game);
}
