/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agvincen <agvincen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 15:07:16 by agvincen          #+#    #+#             */
/*   Updated: 2023/09/07 17:07:57 by agvincen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	handle_error(const char *msg)
{
	perror(msg);
	exit(1);
}

void	free_array(char **arr)
{
	int	i;

	i = 0;
	if (arr)
	{
		while (arr[i])
		{
			free(arr[i]);
			i++;
		}
		free(arr);
	}
}

void	ft_exit(t_data *game)
{
	int	i;

	i = 0;
	if (game->mlx)
		mlx_terminate(game->mlx);
	free_array(game->map);
	free_array(game->map_copy);
	if (game->texture)
		free(game->texture);
	if (game->img)
		free(game->img);
	exit(0);
}
