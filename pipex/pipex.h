/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agheredi <agheredi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 16:11:57 by agheredi          #+#    #+#             */
/*   Updated: 2023/12/14 16:20:59 by agheredi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "./libft/libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <string.h>
# include <errno.h>

# define NOFILE 404
# define NOREAD 403
# define NOWRITE 402
# define NOEXECUTE 126
# define NOCOMMAND 127

typedef struct s_pipex
{
	char	**comand_1;
	char	**comand_2;
	char	**all_path;
	char	*fd1_name;
	char	*fd2_name;
	int		fd1;
	int		fd2;
}	t_pipex;


//pipex_utils.c
char	**ft_parse_cmds(char **envp);
char	*get_path(t_pipex pipex, char **cmd);

//pipe.c
void	ft_exec(t_pipex pipex, char **cmd, char **env);
void	ft_child1(t_pipex pipex, int *p_fd);
void	ft_child2(t_pipex pipex, int *p_fd);
void	ft_pipex(t_pipex pipex);

//exit.c
void	free_tab(char **tab_str);
void	ft_error_file(int code, char *str);
void	ft_error(int code, char *str);
void	ft_cleanup(t_pipex *pipex);

#endif
