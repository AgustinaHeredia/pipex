/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agusheredia <agusheredia@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 16:11:57 by agheredi          #+#    #+#             */
/*   Updated: 2023/12/13 00:41:13 by agusheredia      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "./libft/libft.h"
# include <stdlib.h>
# include <unistd.h>

typedef struct s_pipex
{
	char	**comand_1;
	char	**comand_2;
	char	**all_path;
	int		infile;
	int		outfile;
	pid_t	pid;
}	t_pipex;

//pipex_utils.c
void	ft_open_files(t_pipex pipex, char **argv);
void	ft_parse_argvs(t_pipex pipex, char **argv);
void	ft_parse_cmds(t_pipex pipex, char **envp);

//pipe.c
void	ft_exec(t_pipex pipex, char **cmd, char **env);
void	ft_parent_child(t_pipex pipex, char **env);

//exit.c
void	free_tab(char **tab_str);

#endif
