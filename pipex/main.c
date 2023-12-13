/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agheredi <agheredi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 16:14:21 by agheredi          #+#    #+#             */
/*   Updated: 2023/12/13 16:40:30 by agheredi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

t_pipex	ft_init_pipex(void)
{
	t_pipex	p;

	p.comand_1 = NULL;
	p.comand_2 = NULL;
	p.all_path = NULL;
	p.infile = 0;
	p.outfile = 1;
	p.pid = 0;
	return (p);
}

int	main(int argc, char **argv, char **envp)
{
	t_pipex	pipex;

	if (argc != 5)
	{
		ft_putstr_fd("Error. El numero de argumentos no es válido.\n", 0);
		return (0);
	}
	pipex = ft_init_pipex();
	ft_open_files(pipex, argv);
	ft_parse_cmds(pipex, envp);
	ft_parse_args(pipex, argv);;
	ft_parent_child(pipex);
	ft_cleanup(pipex);
	return (0);
}
