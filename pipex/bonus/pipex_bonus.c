/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agusheredia <agusheredia@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 12:38:30 by agusheredia       #+#    #+#             */
/*   Updated: 2023/12/27 10:25:02 by agusheredia      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	ft_pipex_multi(t_pipex pipex, char **argv, char **envp)
{
}

int	main(int argc, char **argv, char **envp)
{
	t_pipex	pipex;
	int		i;

	if (argc >= 5)
		ft_error_sms("invalid number of arguments\n");
	pipex.name1 = ft_strdup(argv[1]);
	pipex.name2 = ft_strdup(argv[4]);
	pipex.infile = open(pipex.name1, O_RDONLY);
	pipex.outfile = open(pipex.name2, O_RDWR | O_CREAT | O_TRUNC, 0644);
	pipex.all_path = ft_parse_cmds(envp);
	i = 2;
	while (i < (argc - 3))
	{
		ft_pipex_multi(pipex, argv, envp);
		i++;
	}
	ft_cleanup(&pipex);
	exit(EXIT_SUCCESS);
}
