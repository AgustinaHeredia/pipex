/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   files_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agheredi <agheredi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 12:50:54 by agheredi          #+#    #+#             */
/*   Updated: 2024/01/18 16:19:41 by agheredi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	get_infile(char **argv, t_pipex *pipex)
{
	if (pipex->here_doc == 1)
	{
		ft_here_doc(argv[2], &pipex);
		pipex->infile = open(".here_doc", O_RDONLY);
		if (pipex->infile < 0)
		{
			unlink(".here_doc");
			ft_error_sms("Error en here_doc\n");
		}
	}
	else if (pipex->here_doc == 0)
	{
		pipex->infile = open(argv[1], O_RDONLY);
		if (pipex->infile < 0)
		{
			ft_error(NOFILE, argv[1]);
		}
	}
}

void	get_outfile(char *argv, t_pipex *pipex)
{
	if (pipex->here_doc == 1)
		pipex->outfile = open(argv, O_WRONLY | O_CREAT | O_APPEND, 0644);
	else if (pipex->here_doc == 0)
	{
		pipex->outfile = open(argv, O_RDWR | O_CREAT | O_TRUNC, 0644);
		if (pipex->outfile < 0)
			ft_error(NOFILE, argv);
	}
}
