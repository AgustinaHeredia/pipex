/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agheredi <agheredi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 11:07:18 by agheredi          #+#    #+#             */
/*   Updated: 2023/12/14 15:39:18 by agheredi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

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

void	ft_error_file(int code, char *str)
{
	if (code == NOREAD || code == NOWRITE || code == NOEXECUTE)
	{
		ft_putstr_fd("Pipex: ", 2);
		ft_putstr_fd(str, 2);
		ft_putstr_fd(": Permission denied\n", 2);
	}
	else if (code == NOFILE)
	{
		ft_putstr_fd("Pipex: ", 2);
		ft_putstr_fd(str, 2);
		ft_putstr_fd(": No such file or directory\n", 2);
	}
}

void	ft_error(int code, char *str)
{
	if (code == NOCOMMAND)
	{
		ft_putstr_fd("Pipex: ", 2);
		ft_putstr_fd(str, 2);
		ft_putstr_fd(": Command not found\n", 2);
	}
	else if (code > 400 | code == NOEXECUTE)
	{
		ft_error_file(code, str);
		if (code != NOEXECUTE)
			code = 1;
	}
	else if (str)
	{
		ft_putstr_fd("Pipex: ", 2);
		ft_putstr_fd(str, 2);
		ft_putstr_fd(": ", 2);
		ft_putendl_fd(strerror(code), 2);
	}
	else
		perror("Pipex");
	exit(code);
}

void	ft_cleanup(t_pipex *pipex)
{
	free_tab(pipex->all_path);
	free_tab(pipex->comand_1);
	free_tab(pipex->comand_2);
}
