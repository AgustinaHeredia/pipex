/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agheredi <agheredi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 14:42:03 by agheredi          #+#    #+#             */
/*   Updated: 2023/12/12 15:50:00 by agheredi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	free_array(char **tab_str)
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

void	exit_handler(int n_exit)
{
	if (n_exit == 1)
		ft_putstr_fd("Error al ejecutar el programa\n", 2);
	exit(0);
}

void	exit_handler_free(int n_exit, char **tab_str, char **tab_str2)
{
	if (n_exit == 1)
		ft_putstr_fd("Error al ejecutar el programa\n", 2);
	free_array(tab_str);
	free_array(tab_str2);
	exit(0);
}
