/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agusheredia <agusheredia@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 12:39:21 by agusheredia       #+#    #+#             */
/*   Updated: 2023/12/27 10:22:09 by agusheredia      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

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

typedef struct s_pipex
{
	pid_t	pid1;
	pid_t	pid2;
	char	**cmds;
	char	**all_path;
	int		infile;
	int		outfile;
	char	*name1;
	char	*name2;
	int		here_doc;
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
