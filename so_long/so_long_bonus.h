/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agvincen <agvincen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 15:05:34 by agvincen          #+#    #+#             */
/*   Updated: 2023/09/12 12:29:41 by agvincen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H
# include <errno.h>
# include "./libft/libft.h"
# include "./mlx/include/MLX42/MLX42.h"

# ifndef PX
#  define PX 48
# endif

typedef struct s_textures {
	mlx_texture_t	*floor;
	mlx_texture_t	*wall;
	mlx_texture_t	*collectable;
	mlx_texture_t	*player;
	mlx_texture_t	*back;
	mlx_texture_t	*left;
	mlx_texture_t	*right;
	mlx_texture_t	*enem_left;
	mlx_texture_t	*enem_right;
	mlx_texture_t	*exit;
}				t_textures;

typedef struct s_images {
	mlx_image_t	*floor;
	mlx_image_t	*wall;
	mlx_image_t	*collectable;
	mlx_image_t	*player;
	mlx_image_t	*back;
	mlx_image_t	*left;
	mlx_image_t	*right;
	mlx_image_t	*enem_left;
	mlx_image_t	*enem_right;
	mlx_image_t	*exit;
}				t_images;

typedef struct s_data
{
	t_textures	*texture;
	t_images	*img;
	mlx_t		*mlx;

	int			fd;
	int			rows;
	int			columns;
	int			collec_num;
	int			player_num;
	int			exit_num;
	int			enemy_num;
	int			move_num;
	int			x;
	int			y;
	int			collected;
	int			x_enem;
	int			y_enem;
	int			enem_dir;
	double		enemy_timer;

	char		**map;
	char		**map_copy;
}	t_data;

void	handle_error(const char *msg);
void	ft_exit(t_data *game);
void	free_array(char **arr);
void	ft_map(t_data *game, char *argv);
void	check(t_data *game);
void	ft_textures(t_data *game);
void	get_images(t_data *game);
void	place_images(t_data *game);
void	valid_path(t_data *game);
void	my_key_hook(mlx_key_data_t keydata, void *param);
void	next_element(t_data *game, char c, int x, int y);
void	move_enem(t_data *game);
void	move_right_enem(t_data *game);
void	move_left_enem(t_data *game);
void	ft_counter(t_data *game);

#endif