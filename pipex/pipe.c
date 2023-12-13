/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agusheredia <agusheredia@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 22:43:23 by agusheredia       #+#    #+#             */
/*   Updated: 2023/12/13 00:41:35 by agusheredia      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_exec(t_pipex pipex, char **cmd, char **env)
{
	char	*path;

	path = get_path(cmd[0], env);
	if (execve(path, cmd, env) == -1)
	{
		ft_putstr_fd("pipex: command not found: ", 2);
		ft_putendl_fd(cmd[0], 2);
		ft_free_tab(cmd);
		exit(0);
	}
}

void	ft_parent_child(t_pipex pipex, char **env)
{
	int		p_fd[2];

	pipe(p_fd);
	pipex.pid = fork();
	if (pipex.pid < 0)
		return (perror("Error fork\n"));
	if (pipex.pid != 0)
	{
		dup2(pipex.infile, 0);
		dup2(p_fd[1], 1);
		close(p_fd[0]);
		ft_exec(pipex, pipex.comand_1, env);
	}
	else
	{
		dup2(pipex.outfile, 1);
		dup2(p_fd[0], 0);
		close(p_fd[1]);
		ft_exec(pipex, pipex.comand_2, env);
	}
}
