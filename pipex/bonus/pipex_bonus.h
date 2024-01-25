/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agusheredia <agusheredia@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 11:31:38 by agheredi          #+#    #+#             */
/*   Updated: 2024/01/25 16:25:12 by agusheredia      ###   ########.fr       */
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
	pid_t	pid;
	int		num_cmds;
	int		idx;
	int		**pipe;
	char	**all_path;
	char	**cmd;
	int		infile;
	int		outfile;
	int		here_doc;
}	t_pipex;

void	ft_pipex(t_pipex *pipex, char **envp);

//check_here_doc_bonus.c
int		check_argv(char *argv, t_pipex *pipex);
void	ft_here_doc(char *argv);

//files_bonus.c 
void	get_infile(char **argv, t_pipex *pipex);
void	get_outfile(char *argv, t_pipex *pipex);

//pipex_utils_bonus.c
char	**ft_parse_cmds(char **envp);
char	*get_path(t_pipex *pipex, char **cmd);
int		check_file_perimissions(char *fd_name);
void	ft_get_cmd(t_pipex *pipex, char **argv, int argc);
int		*creat_pipe(t_pipex *pipex);

//childs_bonus.c
void	child(t_pipex *p, char **envp);
void	close_pipes(t_pipex *pipex);

//exit_bonus.c
void	free_tab(char **tab_str);
void	ft_error_sms(char *str);
void	ft_error(int perm, char *str);
void	ft_cleanup(t_pipex *pipex);

#endif