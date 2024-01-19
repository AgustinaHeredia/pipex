/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agheredi <agheredi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 11:31:38 by agheredi          #+#    #+#             */
/*   Updated: 2024/01/19 12:26:15 by agheredi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include "../libft/libft.h"
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
	int		num_cmds;
	char	**all_path;
	char	**cmd;
	int		infile;
	int		outfile;
	int		here_doc;
}	t_pipex;

//check_here_doc_bonus.c
int		check_argv(char *argv, t_pipex *pipex);
void	ft_here_doc(char *argv, t_pipex *pipex);

//files_bonus.c 
void	get_infile(char **argv, t_pipex *pipex);
void	get_outfile(char *argv, t_pipex *pipex);

//pipex_utils_bonus.c
char	**ft_parse_cmds(char **envp);
char	*get_path(t_pipex pipex, char **cmd);
int		check_file_perimissions(char *fd_name);

//childs_bonus.c
void	ft_child_1(t_pipex pipex, int *p_fd,char *argv, char **env);
void	ft_child2(t_pipex pipex, int *p_fd, char **env);

//exit_bonus.c
void	free_tab(char **tab_str);
void	ft_error_sms(char *str);
void	ft_error(int perm, char *str);
void	ft_cleanup(t_pipex *pipex);

#endif