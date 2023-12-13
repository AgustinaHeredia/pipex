/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agusheredia <agusheredia@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 14:42:03 by agheredi          #+#    #+#             */
/*   Updated: 2023/12/13 00:43:02 by agusheredia      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_open_files(t_pipex pipex, char **argv)
{
	pipex.infile = open(argv[1], O_RDONLY, 0777);
	if (pipex.infile < 0)
	{
		ft_putstr_fd("Error al abrir el archivo de input.\n", 0);
		return (0);
	}
	pipex.outfile = open(argv[4], O_CREAT | O_WRONLY | O_TRUNC, 0660);
	if (pipex.outfile < 0)
	{
		ft_putstr_fd("Error al abrir el archivo de output.\n", 0);
		return (0);
	}
}

void	ft_parse_argvs(t_pipex pipex, char **argv)
{
	pipex.comand_1 = ft_split(argv[2], ' ');
	pipex.comand_2 = ft_split(argv[3], ' ');
}

void	ft_parse_cmds(t_pipex pipex, char **envp)
{
	char	*str_path;

	while (ft_strnstr("PATH=", *envp, 5))
		envp++;
	str_path = *envp + 5;
	pipex.all_path = ft_split(str_path, ':');
}

char	*my_getenv(char *name, char **env)
{
	int		i;
	int		j;
	char	*sub;

	i = 0;
	while (env[i])
	{
		j = 0;
		while (env[i][j] && env[i][j] != '=')
			j++;
		sub = ft_substr(env[i], 0, j);
		if (ft_strcmp(sub, name) == 0)
		{
			free(sub);
			return (env[i] + j + 1);
		}
		free(sub);
		i++;
	}
	return (NULL);
}

char	*get_path(t_pipex pipex)
{
	int		i;
	char	*exec;
	char	**allpath;
	char	*path_part;
	char	**s_cmd;

	i = -1;
	while (pipex.all_path[++i])
	{
		path_part = ft_strjoin(pipex.all_path[i], "/");
		exec = ft_strjoin(path_part, s_cmd[0]);
		free(path_part);
		if (access(exec, F_OK | X_OK) == 0)
		{
			ft_free_tab(s_cmd);
			return (exec);
		}
		free(exec);
	}
	ft_free_tab(allpath);
	ft_free_tab(s_cmd);
	return (cmd);
}
