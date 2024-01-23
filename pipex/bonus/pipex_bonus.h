/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agheredi <agheredi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 11:31:38 by agheredi          #+#    #+#             */
/*   Updated: 2024/01/23 14:27:19 by agheredi         ###   ########.fr       */
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

# define READ_END 0
# define WRITE_END 1

typedef struct s_pipex
{
	pid_t	pid1;
	pid_t	pid2;
	int		num_cmds;
	char	**all_path;
	char	**cmd_1;
	char	**cmd_2;
	int		infile;
	int		outfile;
	int		here_doc;
}	t_pipex;

//check_here_doc_bonus.c
int		check_argv(char *argv, t_pipex *pipex);
void	ft_here_doc(char *argv);

//files_bonus.c 
void	get_infile(char **argv, t_pipex *pipex);
void	get_outfile(char *argv, t_pipex *pipex);

//pipex_utils_bonus.c
char	**ft_parse_cmds(char **envp);
char	*get_path(t_pipex pipex, char **cmd);
int		check_file_perimissions(char *fd_name);

//childs_bonus.c
void	ft_child_1(t_pipex pipex, int *p_fd, char *argv, char **env);
void	ft_child_2(t_pipex pipex, int *p_fd, char *cmd, char **env);
void	otherchild(t_pipex pipex, int *p_fd, char *argv, char **env);

//exit_bonus.c
void	free_tab(char **tab_str);
void	ft_error_sms(char *str);
void	ft_error(int perm, char *str);
void	ft_cleanup(t_pipex *pipex);

#endif
