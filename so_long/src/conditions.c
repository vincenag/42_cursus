/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conditions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agvincen <agvincen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 12:44:40 by agvincen          #+#    #+#             */
/*   Updated: 2023/09/12 12:51:20 by agvincen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	next_element(t_data *game, char c, int x, int y)
{
	if (c == 'C')
	{	
		mlx_image_to_window(game->mlx, game->img->floor, x * PX, y * PX);
		game->collected++;
		game->map[y][x] = '0';
		ft_printf("Collected items:%i/%i\n", game->collected, game->collec_num);
	}
	if (c == 'E')
	{
		if (game->collected == game->collec_num)
			mlx_close_window(game->mlx);
	}
}
