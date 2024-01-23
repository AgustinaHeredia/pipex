/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agheredi <agheredi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 12:49:11 by agheredi          #+#    #+#             */
/*   Updated: 2024/01/23 10:30:13 by agheredi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	free_tab(char **tab_str)
{
	int	i;

	i = 0;
	while (tab_str[i])
	{
		free(tab_str[i]);
		i++;
	}
	free(tab_str);
}

void	ft_error_sms(char *str)
{
	ft_putstr_fd("Pipex: ", 2);
	ft_putstr_fd(str, 2);
	exit(1);
}

void	ft_error(int perm, char *str)
{
	if (perm == NOREAD || perm == NOWRITE)
	{
		ft_putstr_fd("Pipex: ", 2);
		ft_putstr_fd(str, 2);
		ft_putstr_fd(": Permission denied\n", 2);
	}
	else if (perm == 404)
	{
		ft_putstr_fd("Pipex: ", 2);
		ft_putstr_fd(str, 2);
		ft_putstr_fd(": No such file or directory\n", 2);
	}
	else if (perm == NOCMD)
	{
		ft_putstr_fd("Pipex: ", 2);
		ft_putstr_fd(": command not found: ", 2);
		ft_putendl_fd(str, 2);
	}
	exit(1);
}

void	ft_cleanup(t_pipex *pipex)
{
	close(pipex->infile);
	close(pipex->outfile);
	free_tab(pipex->all_path);
}
