/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   childs_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agheredi <agheredi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 16:43:35 by agheredi          #+#    #+#             */
/*   Updated: 2024/01/19 12:27:27 by agheredi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	ft_child_1(t_pipex pipex, int *p_fd,char *argv, char **env)
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
	path = get_path(pipex, pipex.cmd);
	if (path == NULL)
		ft_error(NOCMD, pipex.cmd_2[0]);
	execve(path, pipex.cmd_2, env);
}

