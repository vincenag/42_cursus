/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agvincen <agvincen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 17:30:44 by agvincen          #+#    #+#             */
/*   Updated: 2023/08/10 16:09:00 by agvincen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	parent_process(int end[2])
{
	close(end[1]);
	dup2(end[0], STDIN_FILENO);
	wait(0);
}

void	child_process(char *argv, char **envp)
{
	pid_t	id;
	int		end[2];

	if (pipe(end) < 0)
		handle_error("Something went wrong with pipe\n");
	id = fork();
	if (id < 0)
		handle_error("Something went wrong when forking\n");
	if (id == 0)
	{
		close(end[0]);
		dup2(end[1], STDOUT_FILENO);
		execute(argv, envp);
	}
	else
		parent_process(end);
}

void	here_doc(char *limiter, int argc)
{
	pid_t	id;
	int		end[2];
	char	*line;

	if (argc == 5)
		handle_error("Invalid number of arguments\n");
	if (pipe(end) < 0)
		handle_error("Something went wrong with pipe\n");
	id = fork();
	if (id < 0)
		handle_error("Something went wrong when forking\n");
	else if (id == 0)
	{
		close(end[0]);
		ft_putstr_fd("heredoc>\n", 1);
		line = get_next_line(0);
		while (ft_strncmp(line, limiter, ft_strlen(line)) != '\n')
		{
			ft_putstr_fd(line, end[1]);
			line = get_next_line(0);
		}
		exit(0);
	}
	parent_process(end);
}

int	main(int argc, char **argv, char **envp)
{
	int	filein;
	int	fileout;
	int	i;

	if (argc >= 5)
	{
		if (ft_strncmp(argv[1], "here_doc", 8) == 0)
		{
			i = 3;
			fileout = open(argv[argc - 1], O_WRONLY | O_CREAT | O_APPEND, 0777);
			here_doc(argv[2], argc);
		}
		else
		{
			i = 2;
			filein = open(argv[1], O_RDONLY, 0777);
			fileout = open(argv[argc - 1], O_WRONLY | O_CREAT | O_TRUNC, 0777);
			dup2(filein, STDIN_FILENO);
		}
		while (i < argc - 2)
			child_process(argv[i++], envp);
		dup2(fileout, STDOUT_FILENO);
		execute(argv[argc - 2], envp);
	}
	return (0);
}
