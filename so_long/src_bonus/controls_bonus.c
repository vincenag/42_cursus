/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agvincen <agvincen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 11:55:07 by agvincen          #+#    #+#             */
/*   Updated: 2023/09/12 12:37:47 by agvincen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

void	move_up(t_data *game)
{
	next_element(game, game->map[game->y - 1][game->x], game->x, game->y - 1);
	if (game->map[game->y - 1][game->x] != '1')
	{
		mlx_image_to_window(game->mlx, game->img->floor, game->x * PX, game->y
			* PX);
		mlx_image_to_window(game->mlx, game->img->back, game->x * PX, (game->y
				- 1) * PX);
		if (game->map[game->y][game->x] == 'E')
			mlx_image_to_window(game->mlx, game->img->exit, game->x * PX,
				game->y * PX);
		game->y -= 1;
		game->move_num++;
		ft_counter(game);
	}
}

void	move_down(t_data *game)
{
	next_element(game, game->map[game->y + 1][game->x], game->x, game->y + 1);
	if (game->map[game->y + 1][game->x] != '1')
	{
		mlx_image_to_window(game->mlx, game->img->floor, game->x * PX, game->y
			* PX);
		mlx_image_to_window(game->mlx, game->img->player, game->x * PX, (game->y
				+ 1) * PX);
		if (game->map[game->y][game->x] == 'E')
			mlx_image_to_window(game->mlx, game->img->exit, game->x * PX,
				game->y * PX);
		game->y += 1;
		game->move_num++;
		ft_counter(game);
	}
}

void	move_left(t_data *game)
{
	next_element(game, game->map[game->y][game->x - 1], game->x - 1, game->y);
	if (game->map[game->y][game->x - 1] != '1')
	{
		mlx_image_to_window(game->mlx, game->img->floor, game->x * PX, game->y
			* PX);
		mlx_image_to_window(game->mlx, game->img->left, (game->x - 1) * PX,
			game->y * PX);
		if (game->map[game->y][game->x] == 'E')
			mlx_image_to_window(game->mlx, game->img->exit, game->x * PX,
				game->y * PX);
		game->x -= 1;
		game->move_num++;
		ft_counter(game);
	}
}

void	move_right(t_data *game)
{
	next_element(game, game->map[game->y][game->x + 1], game->x + 1, game->y);
	if (game->map[game->y][game->x + 1] != '1')
	{
		mlx_image_to_window(game->mlx, game->img->floor, game->x * PX, game->y
			* PX);
		mlx_image_to_window(game->mlx, game->img->right, (game->x + 1) * PX,
			game->y * PX);
		if (game->map[game->y][game->x] == 'E')
			mlx_image_to_window(game->mlx, game->img->exit, game->x * PX,
				game->y * PX);
		game->x += 1;
		game->move_num++;
		ft_counter(game);
	}
}

void	my_key_hook(mlx_key_data_t keydata, void *param)
{
	t_data	*game;

	game = param;
	if ((keydata.key == MLX_KEY_W && keydata.action == MLX_RELEASE)
		|| (keydata.key == MLX_KEY_UP && keydata.action == MLX_RELEASE))
		move_up(game);
	if ((keydata.key == MLX_KEY_S && keydata.action == MLX_RELEASE)
		|| (keydata.key == MLX_KEY_DOWN && keydata.action == MLX_RELEASE))
		move_down(game);
	if ((keydata.key == MLX_KEY_A && keydata.action == MLX_RELEASE)
		|| (keydata.key == MLX_KEY_LEFT && keydata.action == MLX_RELEASE))
		move_left(game);
	if ((keydata.key == MLX_KEY_D && keydata.action == MLX_RELEASE)
		|| (keydata.key == MLX_KEY_RIGHT && keydata.action == MLX_RELEASE))
		move_right(game);
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_RELEASE)
		mlx_close_window(game->mlx);
}
