/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agheredi <agheredi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 11:07:42 by agheredi          #+#    #+#             */
/*   Updated: 2023/12/14 16:20:46 by agheredi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_exec(t_pipex pipex, char **cmd, char **env)
{
	char	*path;

	path = get_path(pipex, cmd);
	if (execve(path, cmd, env) == -1)
		ft_error(NOEXECUTE, cmd[0]);
}

void	ft_child1(t_pipex pipex, int *p_fd)
{
	dup2(pipex.fd1, 0);
	close(p_fd[0]);
	dup2(p_fd[1], 1);
	ft_exec(pipex, pipex.comand_1, NULL);
	close(p_fd[1]);
	exit(0);
}

void	ft_child2(t_pipex pipex, int *p_fd)
{
	close(p_fd[1]);
	dup2(p_fd[0], 0);
	dup2(pipex.fd2, 1);
	ft_exec(pipex, pipex.comand_2, NULL);
	close(p_fd[0]);
}

void	ft_pipex(t_pipex pipex)
{
	int		p_fd[2];
	pid_t	id;
	pid_t	id2;
	int		status;

	if (pipe(p_fd) == -1)
		ft_error(errno, NULL);
	id = fork();
	if (id < 0)
		ft_error(errno, NULL);
	else if (id == 0)
		ft_child1(pipex, p_fd);
	id2 = fork();
	if (id2 < 0)
		ft_error(errno, NULL);
	else if (id2 == 0)
		ft_child2(pipex, p_fd);
	waitpid(id, &status, 0);
	if (WIFEXITED(status) != 0)
		exit(WEXITSTATUS(status));
}
