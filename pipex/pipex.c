/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agvincen <agvincen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 19:34:07 by agvincen          #+#    #+#             */
/*   Updated: 2023/08/10 14:27:04 by agvincen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	parent_process(char **argv, char **envp, int *end)
{
	int	fileout;

	close(end[1]);
	fileout = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (fileout < 0)
		handle_error("open error");
	if (dup2(end[0], STDIN_FILENO) < 0)
		handle_error("dup2 error");
	if (dup2(fileout, STDOUT_FILENO) < 0)
		handle_error("dup2 error");
	execute(argv[3], envp);
}

void	child_process(char **argv, char **envp, int *end)
{
	int	filein;

	close(end[0]);
	filein = open(argv[1], O_RDONLY, 0777);
	if (filein < 0)
		handle_error("open error in input file");
	if (dup2(filein, STDIN_FILENO) < 0)
		handle_error("dup2 error");
	if (dup2(end[1], STDOUT_FILENO) < 0)
		handle_error("dup2 error");
	execute(argv[2], envp);
}

int	main(int argc, char **argv, char **envp)
{
	int		end[2];
	pid_t	id;

	if (argc != 5)
		ft_putstr_fd("Invalid number of arguments", 2);
	else
	{
		if (pipe(end) < 0)
			handle_error("Something went wrong with pipe\n");
		id = fork();
		if (id < 0)
			handle_error("Something went wrong when forking\n");
		if (id == 0)
			child_process(argv, envp, end);
		wait(NULL);
		parent_process(argv, envp, end);
	}
	return (0);
}
