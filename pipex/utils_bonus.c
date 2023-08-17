/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agvincen <agvincen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 21:20:16 by agvincen          #+#    #+#             */
/*   Updated: 2023/08/10 13:26:39 by agvincen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	handle_error(const char *msg)
{
	perror(msg);
	exit(1);
}

void	free_split(char **arr)
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

char	*findpath(char *cmd, char **envp)
{
	int		i;
	char	**paths_array;
	char	*temp;
	char	*path;

	i = 0;
	while (ft_strnstr(envp[i], "PATH", 4) == 0)
		i++;
	paths_array = ft_split(envp[i] + 5, ':');
	i = 0;
	while (paths_array[i])
	{
		temp = ft_strjoin(paths_array[i], "/");
		path = ft_strjoin(temp, cmd);
		free (temp);
		if (access(path, F_OK) == 0)
			return (path);
		free(path);
		i++;
	}
	free_split(paths_array);
	return (0);
}

void	execute(char *argv, char **envp)
{
	char	**cmd;
	char	*path;

	cmd = ft_split(argv, ' ');
	path = findpath(cmd[0], envp);
	if (!path)
	{
		free_split(cmd);
		handle_error("path not found\n");
	}
	execve(path, cmd, envp);
}
