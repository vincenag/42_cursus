/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agvincen <agvincen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 12:14:01 by agvincen          #+#    #+#             */
/*   Updated: 2023/09/12 13:08:43 by agvincen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

/* void	ft_leaks(void)
{
	system("leaks -q so_long");
} */
//atexit(ft_leaks);

void	ft_loop(void *param)
{
	t_data	*game;

	game = param;
	move_enem(game);
}

void	resizable(int32_t width, int32_t height, void *param)
{
	(void)param;
	(void)width;
	(void)height;
	mlx_set_setting(MLX_STRETCH_IMAGE, 1);
}

int	main(int argc, char **argv)
{
	t_data	*game;

	if (argc != 2)
		return (1);
	game = ft_calloc(1, sizeof(t_data));
	ft_map(game, argv[1]);
	check(game);
	valid_path(game);
	game->mlx = mlx_init(game->columns * PX, game->rows * PX, "so_long", 1);
	if (!game->mlx)
		exit (1);
	ft_textures(game);
	get_images(game);
	place_images(game);
	game->enem_dir = 1;
	mlx_resize_hook(game->mlx, &resizable, game);
	mlx_key_hook(game->mlx, &my_key_hook, game);
	mlx_loop_hook(game->mlx, ft_loop, game);
	mlx_loop(game->mlx);
	ft_exit(game);
	return (0);
}
