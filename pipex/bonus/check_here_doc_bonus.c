/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_here_doc_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agheredi <agheredi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 12:38:03 by agheredi          #+#    #+#             */
/*   Updated: 2024/01/17 15:19:18 by agheredi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int	check_argv(char *argv, t_pipex *pipex)
{
	if (ft_strncmp(argv, " here_doc", 9) == 0)
	{
		pipex->here_doc = 1;
		return (6);
	}
	else
	{
		pipex->here_doc = 0;
		return (5);
	}
}

void	ft_here_doc(char **argv, t_pipex *pipex)
{
	pipex->name1 = ".heredoc\0";
	pipex->infile = open(pipex->name1, O_CREAT | O_RDWR | O_TRUNC, 0644);
}
