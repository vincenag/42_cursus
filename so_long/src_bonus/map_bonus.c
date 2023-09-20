/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agvincen <agvincen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 13:05:34 by agvincen          #+#    #+#             */
/*   Updated: 2023/09/07 15:35:25 by agvincen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

int	length(char *line, t_data *game)
{
	int	columns;

	columns = game->columns;
	if (line[columns - 1] == '\n')
		return (0);
	else
		return (1);
}

void	check_extension(const char *str)
{
	int	i;

	i = ft_strlen(str) - 1;
	if (str[i] != 'r' || str[i - 1] != 'e'
		|| str[i - 2] != 'b'
		|| str[i - 3] != '.')
	{
		ft_putstr_fd("Error!\nWrong map extension\n", 2);
		exit (1);
	}
}

void	add_row(t_data *game)
{
	char	*line;
	int		i;
	int		add;

	game->map = (char **)ft_calloc(game->rows + 1, sizeof(char *));
	game->map_copy = (char **)ft_calloc(game->rows + 1, sizeof(char *));
	line = get_next_line(game->fd);
	i = 0;
	while (line)
	{
		game->columns = ft_strlen(line);
		add = length(line, game);
		game->map[i] = ft_calloc(game->columns + add, sizeof(char));
		game->map_copy[i] = ft_calloc(game->columns + add, sizeof(char));
		ft_strlcpy(game->map[i], line, game->columns + add);
		ft_strlcpy(game->map_copy[i], line, game->columns + add);
		i++;
		free(line);
		line = get_next_line(game->fd);
	}
	if (add == 0)
		game->columns--;
	free(line);
	game->map[i] = NULL;
	game->map_copy[i] = NULL;
}

void	ft_map(t_data *game, char *argv)
{
	char	*line;

	check_extension(argv);
	game->fd = open(argv, O_RDONLY);
	if (game->fd < 0)
		handle_error("Error with map file");
	line = get_next_line(game->fd);
	while (line)
	{
		game->rows++;
		free(line);
		line = get_next_line(game->fd);
	}
	free(line);
	close(game->fd);
	game->fd = open(argv, O_RDONLY);
	add_row(game);
	close(game->fd);
}
