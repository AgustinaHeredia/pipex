/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agheredi <agheredi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 14:42:03 by agheredi          #+#    #+#             */
/*   Updated: 2023/12/14 14:21:31 by agheredi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	**ft_parse_cmds(char **envp)
{
	char	*str_path;
	char	**all_path;

	while (*envp != NULL)
	{
		if (ft_strncmp(*envp, "PATH=", 5) == 0)
			str_path = (*envp) + 5;
		envp++;
	}
	all_path = ft_split(str_path, ':');
	return (all_path);
}

char	*get_path(t_pipex pipex, char **cmd)
{
	int		i;
	char	*exec;
	char	*path_part;

	if (pipex.all_path == NULL || cmd == NULL || cmd[0] == NULL)
		return (NULL);
	i = 0;
	while (pipex.all_path[i] != NULL)
	{
		path_part = ft_strjoin("/", pipex.all_path[i]);
		exec = ft_strjoin(cmd[0], path_part);
		free(path_part);
		if (access(exec, F_OK) == 0)
		{
			return (exec);
		}
		free(exec);
		i++;
	}
	return (cmd[0]);
}
