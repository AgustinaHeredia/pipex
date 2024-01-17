/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agheredi <agheredi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 16:11:57 by agheredi          #+#    #+#             */
/*   Updated: 2024/01/17 12:06:19 by agheredi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "./libft/libft.h"
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <errno.h>
# include <string.h>
# include <sys/wait.h>

# define NOFILE 404
# define NOREAD 403
# define NOWRITE 402
# define NOCMD 127

typedef struct s_pipex
{
	pid_t	pid1;
	pid_t	pid2;
	char	**cmd_1;
	char	**cmd_2;
	char	**all_path;
	int		infile;
	int		outfile;
	char	*name1;
	char	*name2;
}	t_pipex;

//pipex_utils.c
char	**ft_parse_cmds(char **envp);
char	*get_path(t_pipex pipex, char **cmd);
int		check_file_perimissions(char *fd_name);

//pipe.c
void	ft_child1(t_pipex pipex, int *p_fd, char **env);
void	ft_child2(t_pipex pipex, int *p_fd, char **env);
void	ft_pipex(t_pipex pipex, char **env);

//exit.c
void	free_tab(char **tab_str);
void	ft_error_sms(char *str);
void	ft_error(int perm, char *str);
void	ft_cleanup(t_pipex *pipex);

#endif
