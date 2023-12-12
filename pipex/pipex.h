/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agheredi <agheredi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 16:11:57 by agheredi          #+#    #+#             */
/*   Updated: 2023/12/12 17:35:08 by agheredi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "./libft/libft.h"
# include <stdlib.h>

typedef struct s_pipex
{
	char	*file_1;
	char	**comand_1;
	char	**comand_2;
	char	*file_2;
	char	**all_path;
	int		fd1;
	int		fd2;
	pid_t	pid;
}	t_pipex;

void	ft_init_pipex(t_pipex pipex, char **argv);
void	ft_open_files(t_pipex pipex);
void	ft_parse_cmds(t_pipex pipex, char *envp);

//pipex_utils.c
void	free_array(char **tab_str);
void	exit_handler(int n_exit);
void	exit_handler_free(int n_exit, char **tab_str, char **tab_str2);

#endif
