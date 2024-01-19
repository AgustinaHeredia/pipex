/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agheredi <agheredi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 12:50:02 by agheredi          #+#    #+#             */
/*   Updated: 2024/01/19 15:17:56 by agheredi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

char	**ft_parse_cmds(char **envp)
{
	char	*str_path;
	char	**all_path;

	while (*envp != NULL)
	{
		if (ft_strncmp(*envp, "PATH=", 5) == 0)
			str_path = ft_strdup(*envp + 5);
		envp++;
	}
	all_path = ft_split(str_path, ':');
	free(str_path);
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
		path_part = ft_strjoin(pipex.all_path[i], "/");
		exec = ft_strjoin(path_part, cmd[0]);
		free(path_part);
		if (access(exec, F_OK) == 0)
			return (exec);
		free(exec);
		i++;
	}
	return (NULL);
}

int	check_file_perimissions(char *fd_name)
{
	int	perm;

	perm = 0;
	if (access(fd_name, F_OK) < 0)
		perm = NOFILE;
	else if (access(fd_name, R_OK) < 0)
		perm = NOREAD;
	else if (access(fd_name, W_OK) < 0)
		perm = NOWRITE;
	return (perm);
}
