/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agheredi <agheredi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 11:30:53 by agheredi          #+#    #+#             */
/*   Updated: 2024/01/18 16:08:23 by agheredi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int	main(int argc, char **argv, char **envp)
{
	t_pipex	pipex;
	int		i;

	if (argc < check_argv(argv[1], &pipex))
		ft_error_sms("invalid number of arguments\n");
	get_infile(argv, &pipex);
	get_outfile(argv[argc - 1], &pipex);
	pipex.all_path = ft_parse_cmds(envp);
	pipex.num_cmds = argc - (3 + pipex.here_doc);
	i = 0;
	while (i < pipex.num_cmds)
	{
		ft_pipex_multi(pipex, argv, envp);
		i++;
	}
	ft_cleanup(&pipex);
	exit(EXIT_SUCCESS);
}
