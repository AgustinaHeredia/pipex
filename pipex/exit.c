/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agusheredia <agusheredia@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 11:07:18 by agheredi          #+#    #+#             */
/*   Updated: 2023/12/19 00:07:12 by agusheredia      ###   ########.fr       */
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

void	ft_error_sms(char *str)
{
	ft_putstr_fd("Pipex: ", 2);
	ft_putstr_fd(str, 2);
	exit(1);
}

void	ft_error(char *str)
{
	perror(str);
	exit(1);
}

void	ft_cleanup(t_pipex *pipex)
{
	close(pipex->infile);
	close(pipex->outfile);
	free_tab(pipex->all_path);
	free_tab(pipex->cmd_1);
	free_tab(pipex->cmd_2);
}
