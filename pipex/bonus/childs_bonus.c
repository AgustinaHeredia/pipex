/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   childs_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agusheredia <agusheredia@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 16:43:35 by agheredi          #+#    #+#             */
/*   Updated: 2024/01/25 22:50:55 by agusheredia      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

static void	sub_dup2(int zero, int first)
{
	dup2(zero, 0);
	dup2(first, 1);
}

void	child(t_pipex *p, char **envp)
{
	char	*path;
	char	**cmd;

	p->pid = fork();
	if (!p->pid)
	{
		if (p->idx == 0)
			sub_dup2(p->infile, p->pipe[p->idx][1]);
		else if (p->idx == (p->num_cmds - 1))
			sub_dup2(p->pipe[p->idx - 1][0], p->outfile);
		else
			sub_dup2(p->pipe[p->idx -1][0], p->pipe[p->idx][1]);
		close_pipes(p);
		cmd = ft_split(p->cmd[p->idx], ' ');
		path = get_path(p, cmd);
		if (path == NULL)
			ft_error(NOCMD, cmd[0]);
		execve(path, cmd, envp);
		free(path);
		free(cmd);
	}
}

void	close_pipes(t_pipex *pipex)
{
	int	i;

	i = 0;
	while (i < pipex->num_cmds - 1)
	{
		close(pipex->pipe[i][0]);
		close(pipex->pipe[i][1]);
		i++;
	}
}
