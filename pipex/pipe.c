/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agheredi <agheredi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 11:07:42 by agheredi          #+#    #+#             */
/*   Updated: 2024/01/17 10:15:12 by agheredi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_child1(t_pipex pipex, int *p_fd, char **env)
{
	char	*path;
	int		perm;

	perm = check_file_perimissions(pipex.name1);
	if (perm != 0)
		ft_error(perm, pipex.name1);
	close(p_fd[0]);
	dup2(p_fd[1], 1);
	dup2(pipex.infile, 0);
	close(pipex.infile);
	path = get_path(pipex, pipex.cmd_1);
	if (path == NULL)
		ft_error(NOCMD, pipex.cmd_1[0]);
	execve(path, pipex.cmd_1, env);
}

void	ft_child2(t_pipex pipex, int *p_fd, char **env)
{
	char	*path;
	int		perm;

	perm = check_file_perimissions(pipex.name2);
	if (perm != 0)
		ft_error(perm, pipex.name2);
	close(p_fd[1]);
	dup2(p_fd[0], 0);
	dup2(pipex.outfile, 1);
	close(pipex.outfile);
	path = get_path(pipex, pipex.cmd_2);
	if (path == NULL)
		ft_error(NOCMD, pipex.cmd_2[0]);
	execve(path, pipex.cmd_2, env);
}

void	ft_pipex(t_pipex pipex, char **env)
{
	int		p_fd[2];

	pipe(p_fd);
	pipex.pid1 = fork();
	if (pipex.pid1 == 0)
		ft_child1(pipex, p_fd, env);
	pipex.pid2 = fork();
	if (pipex.pid2 == 0)
		ft_child2(pipex, p_fd, env);
	close(p_fd[0]);
	close(p_fd[1]);
	waitpid(pipex.pid1, NULL, 0);
	waitpid(pipex.pid2, NULL, 0);
}
