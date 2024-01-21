/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agusheredia <agusheredia@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 11:30:53 by agheredi          #+#    #+#             */
/*   Updated: 2024/01/21 09:21:48 by agusheredia      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	pipe_loop(int argc, t_pipex pipex, char **argv, char **envp)
{
	int	p_fd[2];
	int	i;

	i = 2;
	if (pipex.here_doc)
		i = 3;
	while (i < argc -2)
	{
		pipe(p_fd);
		pipex.pid1 = fork();
		if (pipex.pid1 < 0)
			ft_error_sms("fork error\n");
		if (pipex.pid1 == 0)
			ft_child_1(pipex, p_fd, argv[i], envp);
		i++;
	}
	ft_child_2(pipex, p_fd, argv[argc - 2], envp);
	close(p_fd[0]);
	close(p_fd[1]);
	waitpid(pipex.pid1, NULL, 0);
	waitpid(pipex.pid2, NULL, 0);
}

int	main(int argc, char **argv, char **envp)
{
	t_pipex	pipex;

	if (argc < check_argv(argv[1], &pipex))
		ft_error_sms("invalid number of arguments\n");
	get_infile(argv, &pipex);
	get_outfile(argv[argc - 1], &pipex);
	pipex.all_path = ft_parse_cmds(envp);
	pipe_loop(argc, pipex, argv, envp);
	ft_cleanup(&pipex);
	exit(EXIT_SUCCESS);
}
