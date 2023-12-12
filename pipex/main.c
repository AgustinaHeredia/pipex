/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agheredi <agheredi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 16:14:21 by agheredi          #+#    #+#             */
/*   Updated: 2023/12/12 17:35:11 by agheredi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_init_pipex(t_pipex pipex, char **argv)
{
	pipex.file_1 = argv[1];
	pipex.file_2 = argv[4];
	pipex.comand_1 = ft_split(argv[2], ' ');
	pipex.comand_2 = ft_split(argv[3], ' ');
}

void	ft_open_files(t_pipex pipex)
{
	pipex.fd1 = open(pipex.file_1, O_RDONLY, 0777);
	if (pipex.fd1 < 0)
		exit_handler_free(1, pipex.comand_1, pipex.comand_2);
	pipex.fd2 = open(pipex.file_2, O_CREAT | O_WRONLY | O_TRUNC, 0660);
	if (pipex.fd2 < 0)
		exit_handler_free(1, pipex.comand_1, pipex.comand_2);
}

void	ft_parse_cmds(t_pipex pipex, char *envp)
{
	char	*str_path;

	str_path = ft_strnstr(envp, "PATH=", 5);
	pipex.all_path = ft_split(&, ':');
}

int	main(int argc, char **argv, char *envp)
{
	t_pipex	pipex;

	if (argc != 5)
		exit_handler(1);
	ft_init_pipex(pipex, argv);
	ft_open_files(pipex);
	ft_parse_cmds(pipex, envp);
	ft_parse_args()
	//while (cmds)
	//	ft_exec()
	//ft_cleanup()
	return (0);
}
