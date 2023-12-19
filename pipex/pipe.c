/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agusheredia <agusheredia@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 11:07:42 by agheredi          #+#    #+#             */
/*   Updated: 2023/12/19 00:03:41 by agusheredia      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_exec(t_pipex pipex, char **cmd, char **env)
{
	char	*path;

	path = get_path(pipex, cmd);
	execve(path, cmd, env);
}

void	ft_child1(t_pipex pipex, int *p_fd, char **env)
{
	dup2(p_fd[1], 1);
	close(p_fd[0]);
	dup2(pipex.infile, 0);
	ft_exec(pipex, pipex.cmd_1, env);
}

void	ft_child2(t_pipex pipex, int *p_fd, char **env)
{
	dup2(p_fd[0], 0);
	close(p_fd[1]);
	dup2(pipex.outfile, 1);
	ft_exec(pipex, pipex.cmd_2, env);
}

void	ft_pipex(t_pipex pipex, char **env)
{
	int		p_fd[2];

	if (pipe(p_fd) == -1)
		ft_error("Pipe");
	pipex.pid1 = fork();
	if (pipex.pid1 == 0)
		ft_child1(pipex, p_fd, env);
	pipex.pid2 = fork();
	if (pipex.pid1 == 0)
		ft_child2(pipex, p_fd, env);
	close(p_fd[0]);
	close(p_fd[1]);
	waitpid(pipex.pid1, NULL, 0);
	waitpid(pipex.pid2, NULL, 0);
}
