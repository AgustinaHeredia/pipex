/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agheredi <agheredi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 11:07:42 by agheredi          #+#    #+#             */
/*   Updated: 2023/12/13 17:57:23 by agheredi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_exec(t_pipex pipex, char **cmd, char **env)
{
	char	*path;

	printf("del pipex: %s\n", pipex.comand_1[0]);
	printf("de argv: %s\n", cmd[0]);
	path = get_path(pipex, cmd);
	if (execve(path, cmd, env) == -1)
	{
		ft_putstr_fd("pipex: command not found: ", 2);
		ft_putendl_fd(cmd[0], 2);
		ft_putstr_fd("\n", 2);
		free_tab(cmd);
		exit(1);
	}
}

void	ft_parent_child(t_pipex pipex)
{
	int		p_fd[2];

	if (pipe(p_fd) == -1)
		exit(EXIT_FAILURE);
	pipex.pid = fork();
	if (pipex.pid == 0)
	{
		dup2(pipex.infile, 0);
		close(p_fd[0]);
		dup2(p_fd[1], 1);
		ft_exec(pipex, pipex.comand_1, NULL);
		close(p_fd[1]);
		exit(0);
	}
	else
	{
		wait(NULL);
		close(p_fd[1]);
		dup2(p_fd[0], 0);
		dup2(pipex.outfile, 1);
		ft_exec(pipex, pipex.comand_2, NULL);
		close(p_fd[0]);
	}
}
