/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agusheredia <agusheredia@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 11:30:53 by agheredi          #+#    #+#             */
/*   Updated: 2024/01/25 22:48:02 by agusheredia      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	ft_pipex(t_pipex *pipex, char **envp)
{
	int	status;
	int	i;

	i = 0;
	while (i < pipex->num_cmds - 1)
	{
		pipex->pipe[i] = malloc(sizeof(int) * 2);
		if (!pipex->pipe[i])
			ft_error_sms("Malloc\n");
		pipe(pipex->pipe[i]);
		i++;
	}
	pipex->idx = 0;
	while (pipex->idx < pipex->num_cmds)
	{
		child(pipex, envp);
		pipex->idx++;
	}
	close_pipes(pipex);
	waitpid(-1, &status, 0);
	if (WEXITSTATUS(status) != 0)
		exit(WEXITSTATUS(status));
}

int	main(int argc, char **argv, char **envp)
{
	t_pipex	pipex;

	if (argc < check_argv(argv[1], &pipex))
		ft_error_sms("invalid number of arguments\n");
	get_infile(argv, &pipex);
	get_outfile(argv[argc - 1], &pipex);
	pipex.all_path = ft_parse_cmds(envp);
	pipex.num_cmds = argc - (3 - pipex.here_doc);
	pipex.pipe = malloc(sizeof(int *) * (pipex.num_cmds - 1));
	if (!pipex.pipe)
		ft_error_sms("Malloc\n");
	ft_get_cmd(&pipex, argv, argc);
	ft_pipex(&pipex, envp);
	close_pipes(&pipex);
	waitpid(-1, NULL, 0);
	ft_cleanup(&pipex);
	exit(EXIT_SUCCESS);
}
