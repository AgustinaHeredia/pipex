/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agheredi <agheredi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 11:07:18 by agheredi          #+#    #+#             */
/*   Updated: 2023/12/13 12:55:53 by agheredi         ###   ########.fr       */
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

void	ft_cleanup(t_pipex pipex)
{
	free_tab(pipex.all_path);
	free_tab(pipex.comand_1);
	free_tab(pipex.comand_2);
}
