/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agusheredia <agusheredia@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 16:14:21 by agheredi          #+#    #+#             */
/*   Updated: 2023/12/18 23:57:50 by agusheredia      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	t_pipex	pipex;

	if (argc != 5)
		ft_error_sms("invalid number of arguments\n");
	pipex.infile = open(argv[1], O_RDONLY);
	if (pipex.infile < 0)
		ft_error("Infile");
	pipex.outfile = open(argv[4], O_RDWR | O_CREAT | O_TRUNC, 0644);
	if (pipex.outfile < 0)
		ft_error("Outfile");
	pipex.all_path = ft_parse_cmds(envp);
	pipex.cmd_1 = ft_split(argv[2], ' ');
	pipex.cmd_2 = ft_split(argv[3], ' ');
	ft_pipex(pipex, envp);
	ft_cleanup(&pipex);
	exit(EXIT_SUCCESS);
}
