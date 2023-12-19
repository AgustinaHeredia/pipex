/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agheredi <agheredi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 16:14:21 by agheredi          #+#    #+#             */
/*   Updated: 2023/12/19 15:28:02 by agheredi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	t_pipex	pipex;

	if (argc != 5)
		ft_error_sms("invalid number of arguments\n");
	pipex.name1 = ft_strdup(argv[1]);
	pipex.name2 = ft_strdup(argv[4]);
	pipex.infile = open(pipex.name1, O_RDONLY);
	pipex.outfile = open(pipex.name2, O_RDWR | O_CREAT | O_TRUNC, 0644);
	pipex.all_path = ft_parse_cmds(envp);
	pipex.cmd_1 = ft_split(argv[2], ' ');
	pipex.cmd_2 = ft_split(argv[3], ' ');
	ft_pipex(pipex, envp);
	ft_cleanup(&pipex);
	exit(EXIT_SUCCESS);
}
