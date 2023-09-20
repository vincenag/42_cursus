/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agvincen <agvincen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 21:09:58 by agvincen          #+#    #+#             */
/*   Updated: 2023/09/08 16:19:17 by agvincen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

void	ft_textures(t_data *game)
{
	game->texture = ft_calloc(1, sizeof(t_textures));
	game->texture->floor = mlx_load_png("img/floor.png");
	game->texture->wall = mlx_load_png("img/wall.png");
	game->texture->player = mlx_load_png("img/player.png");
	game->texture->back = mlx_load_png("img/back.png");
	game->texture->left = mlx_load_png("img/left.png");
	game->texture->right = mlx_load_png("img/right.png");
	game->texture->enem_left = mlx_load_png("img/enem_left.png");
	game->texture->enem_right = mlx_load_png("img/enem_right.png");
	game->texture->exit = mlx_load_png("img/exit.png");
	game->texture->collectable = mlx_load_png("img/pos.png");
}

void	get_images(t_data *game)
{
	game->img = ft_calloc(1, sizeof(t_images));
	game->img->floor = mlx_texture_to_image(game->mlx, game->texture->floor);
	game->img->wall = mlx_texture_to_image(game->mlx, game->texture->wall);
	game->img->collectable = mlx_texture_to_image(game->mlx,
			game->texture->collectable);
	game->img->player = mlx_texture_to_image(game->mlx, game->texture->player);
	game->img->back = mlx_texture_to_image(game->mlx, game->texture->back);
	game->img->left = mlx_texture_to_image(game->mlx, game->texture->left);
	game->img->right = mlx_texture_to_image(game->mlx, game->texture->right);
	game->img->enem_left = mlx_texture_to_image(game->mlx,
			game->texture->enem_left);
	game->img->enem_right = mlx_texture_to_image(game->mlx,
			game->texture->enem_right);
	game->img->exit = mlx_texture_to_image(game->mlx, game->texture->exit);
	mlx_delete_texture(game->texture->floor);
	mlx_delete_texture(game->texture->wall);
	mlx_delete_texture(game->texture->collectable);
	mlx_delete_texture(game->texture->player);
	mlx_delete_texture(game->texture->back);
	mlx_delete_texture(game->texture->left);
	mlx_delete_texture(game->texture->right);
	mlx_delete_texture(game->texture->enem_left);
	mlx_delete_texture(game->texture->enem_right);
	mlx_delete_texture(game->texture->exit);
}

void	ft_elements(char c, t_data *game, int i, int j)
{
	if (c == '1')
		mlx_image_to_window(game->mlx, game->img->wall, j * PX, i * PX);
	if (c == '0')
		mlx_image_to_window(game->mlx, game->img->floor, j * PX, i * PX);
	if (c == 'P')
	{
		mlx_image_to_window(game->mlx, game->img->floor, j * PX, i * PX);
		mlx_image_to_window(game->mlx, game->img->player, j * PX, i * PX);
	}
	if (c == 'E')
		mlx_image_to_window(game->mlx, game->img->exit, j * PX, i * PX);
	if (c == 'C')
	{
		mlx_image_to_window(game->mlx, game->img->floor, j * PX, i * PX);
		mlx_image_to_window(game->mlx, game->img->collectable, j * PX, i * PX);
	}
	if (c == 'Z')
	{
		mlx_image_to_window(game->mlx, game->img->floor, j * PX, i * PX);
		mlx_image_to_window(game->mlx, game->img->enem_left, j * PX, i * PX);
	}
}

void	place_images(t_data *game)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < game->rows)
	{
		while (j < game->columns)
		{
			ft_elements(game->map[i][j], game, i, j);
			j++;
		}
		j = 0;
		i++;
	}
}
