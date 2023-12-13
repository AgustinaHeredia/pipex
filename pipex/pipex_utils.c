/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agheredi <agheredi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 14:42:03 by agheredi          #+#    #+#             */
/*   Updated: 2023/12/13 17:27:03 by agheredi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_open_files(t_pipex pipex, char **argv)
{
	pipex.infile = open(argv[1], O_RDONLY, 0777);
	if (pipex.infile < 0)
	{
		ft_putstr_fd("pipex: no such file or directory: ", 2);
		ft_putendl_fd(argv[1], 2);
		ft_putstr_fd("\n", 2);
		exit(0);
	}
	pipex.outfile = open(argv[4], O_CREAT | O_WRONLY | O_TRUNC, 0660);
	if (pipex.outfile < 0)
	{
		ft_putstr_fd("pipex: no such file or directory: ", 2);
		ft_putendl_fd(argv[4], 2);
		exit(0);
	}
}

void	ft_parse_args(t_pipex pipex, char **argv)
{
	pipex.comand_1 = ft_split(argv[2], ' ');
	pipex.comand_2 = ft_split(argv[3], ' ');
	printf("PARSEdel pipex: %s\n", pipex.comand_1[0]);
}

void	ft_parse_cmds(t_pipex pipex, char **envp)
{
	char	*str_path;

	while (*envp != NULL)
	{
		if (ft_strncmp(*envp, "PATH=", 5) == 0)
			str_path = (*envp) + 5;
		envp++;
	}
	pipex.all_path = ft_split(str_path, ':');
}

char	*get_path(t_pipex pipex, char **cmd)
{
	int		i;
	char	*exec;
	char	*path_part;

	if (pipex.all_path == NULL || cmd == NULL || cmd[0] == NULL)
		return (NULL);
	i = 0;
	printf("hola: %s\n", pipex.all_path[i]);
	while (pipex.all_path[i] != NULL)
	{
		path_part = ft_strjoin("/", pipex.all_path[i]);
		printf("%s\n", path_part);
		exec = ft_strjoin(cmd[0], path_part);
		printf("%s\n", exec);
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
