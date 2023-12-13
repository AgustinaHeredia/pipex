/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agusheredia <agusheredia@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 16:14:21 by agheredi          #+#    #+#             */
/*   Updated: 2023/12/13 00:27:27 by agusheredia      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char *envp)
{
	t_pipex	pipex;

	if (argc != 5)
	{
		ft_putstr_fd("Error. El numero de argumentos no es válido.\n", 0);
		return (0);
	}
	ft_open_files(pipex, argv);
	ft_parse_cmds(pipex, envp);
	ft_parse_args(pipex, argv);
	ft_parent_child(pipex, envp);
	return (0);
}