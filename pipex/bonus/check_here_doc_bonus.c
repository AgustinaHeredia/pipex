/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_here_doc_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agheredi <agheredi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 12:38:03 by agheredi          #+#    #+#             */
/*   Updated: 2024/01/18 16:19:52 by agheredi         ###   ########.fr       */
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

void	ft_here_doc(char *argv, t_pipex *pipex)
{
	int		infile;
	char	*buf;

	infile = open(".here_doc", O_CREAT | O_RDWR | O_TRUNC, 0644);
	if (infile < 0)
		ft_error_sms("Error en el here_doc\n");
	while (1)
	{
		write(1, "heredoc> ", 9);
		buf = get_next_line(0);
		if (!buf)
			exit (1);
		if (!ft_strncmp(argv, buf, ft_strlen(argv) + 1))
			break ;
		write(infile, &buf, ft_strlen(buf));
		write(infile, "\n", 1);
		free(buf);
	}
	free(buf);
	close(infile);
}
