/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   files_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agheredi <agheredi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 12:50:54 by agheredi          #+#    #+#             */
/*   Updated: 2024/01/17 14:58:37 by agheredi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	get_infile(char **argv, t_pipex *pipex)
{
	if (pipex->here_doc == 1)
	{
		ft_here_doc(argv, &pipex);
	}
	else if (pipex->here_doc == 0)
	{
		pipex->name1 = ft_strdup(argv[1]);
		pipex->infile = open(pipex->name1, O_RDONLY);
	}
}

void	get_outfile(char *argv, t_pipex *pipex)
{

}
