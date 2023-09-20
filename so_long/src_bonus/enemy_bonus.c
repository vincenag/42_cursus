/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agvincen <agvincen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 15:02:08 by agvincen          #+#    #+#             */
/*   Updated: 2023/09/12 12:45:16 by agvincen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

static void	ft_c_e(t_data *game)
{
	if (game->map[game->y_enem][game->x_enem] == 'C')
	{
		mlx_image_to_window(game->mlx, game->img->collectable, game->x_enem
			* PX, game->y_enem * PX);
	}
	else if (game->map[game->y_enem][game->x_enem] == 'E')
		mlx_image_to_window(game->mlx, game->img->exit, game->x_enem * PX,
			game->y_enem * PX);
}

void	move_left_enem(t_data *game)
{
	mlx_image_to_window(game->mlx, game->img->floor, game->x_enem * PX,
		game->y_enem * PX);
	mlx_image_to_window(game->mlx, game->img->enem_left, (game->x_enem - 1)
		* PX, game->y_enem * PX);
	ft_c_e(game);
	game->x_enem -= 1;
}

void	move_right_enem(t_data *game)
{
	mlx_image_to_window(game->mlx, game->img->floor, game->x_enem * PX,
		game->y_enem * PX);
	mlx_image_to_window(game->mlx, game->img->enem_right, (game->x_enem + 1)
		* PX, game->y_enem * PX);
	ft_c_e(game);
	game->x_enem += 1;
}

void	move_enem(t_data *game)
{
	game->enemy_timer += game->mlx->delta_time;
	if (game->enemy_timer >= 0.1)
	{
		if (game->enem_dir == 1)
		{
			if (game->map[game->y_enem][game->x_enem - 1] != '1')
				move_left_enem(game);
			else
				game->enem_dir = 0;
		}
		else
		{
			if (game->map[game->y_enem][game->x_enem + 1] != '1')
				move_right_enem(game);
			else
				game->enem_dir = 1;
		}
		game->enemy_timer = 0;
	}
	if (game->x_enem == game->x && game->y_enem == game->y)
	{	
		mlx_close_window(game->mlx);
		ft_printf("YOU LOST :(\n");
	}
}
