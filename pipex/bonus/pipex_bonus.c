/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agheredi <agheredi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 11:30:53 by agheredi          #+#    #+#             */
/*   Updated: 2024/01/23 14:32:25 by agheredi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	pipe_loop(int argc, t_pipex pipex, char **argv, char **envp)
{
	int	p_fd[2];
	int	i;

	i = 2 + pipex.here_doc;
	while (i < argc - 1)
	{
		pipe(p_fd);
		pipex.pid1 = fork();
		if (pipex.pid1 < 0)
			ft_error_sms("fork error\n");
		if (pipex.pid1 == 0)
		{
			if (i == (2 + pipex.here_doc))
				ft_child_1(pipex, p_fd, argv[i], envp);
			else
				otherchild(pipex, p_fd, argv[i], envp);
		}
		close(p_fd[1]);
		pipex.pid2 = fork();
		if (pipex.pid2 < 0)
			ft_error_sms("fork error\n");
		if (pipex.pid2 == 0)
		{
			if (i == argc - 2)
				ft_child_2(pipex, p_fd, argv[i], envp);
		}
		close(p_fd[0]);
		i++;
	}
	
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
