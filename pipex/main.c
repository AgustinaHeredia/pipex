/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agheredi <agheredi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 16:14:21 by agheredi          #+#    #+#             */
/*   Updated: 2023/12/14 15:44:56 by agheredi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	t_pipex	pipex;

	if (argc != 5)
		return (write(2, "Pipex: invalid number of arguments\n", 35), 1);
	pipex.fd1_name = argv[1];
	pipex.fd1_name = argv[argc - 1];
	pipex.fd1 = open(pipex.fd1_name, O_RDONLY);
	if (pipex.fd1 < 0)
		ft_error_file(NOFILE, pipex.fd1_name);
	pipex.fd2 = open(pipex.fd2_name, O_RDWR | O_CREAT | O_TRUNC, 0644);
	if (pipex.fd2 < 0)
		ft_error_file(NOFILE, pipex.fd2_name);
	pipex.all_path = ft_parse_cmds(envp);
	pipex.comand_1 = ft_split(argv[2], ' ');
	pipex.comand_2 = ft_split(argv[3], ' ');
	ft_pipex(pipex);
	ft_cleanup(&pipex);
	exit(EXIT_SUCCESS);
}
