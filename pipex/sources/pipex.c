/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwintgen <rwintgen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 16:19:12 by rwintgen          #+#    #+#             */
/*   Updated: 2024/04/12 15:24:39 by rwintgen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"
#include <stdio.h>

int	main(int argc, char **argv, char **envp)
{
	int		pipefd[2];
	int		filefd[2];
	pid_t	pid[2];

	if (argc != 5)
		return (err_msg(ERR_ARGC));
	if (ft_open(argv[1], &filefd[0], FLAG_READ) < 0)
		err_msg(ERR_INFILE);
	if (ft_open(argv[4], &filefd[1], FLAG_WRITE) < 0)
	{
		if (filefd[0] > -1)
			close(filefd[0]);
		return (err_msg(ERR_OUTFILE));
	}
	if (pipe(pipefd) < 0)
		return (err_msg(ERR_PIPE));
	pid[0] = fork();
	if (!pid[0] && filefd[0] > -1)
		exec_cmd_1(argv[2], pipefd, filefd, envp);
	pid[1] = fork();
	if (!pid[1] && pid[0])
		exec_cmd_2(argv[3], pipefd, filefd, envp);
	close_and_wait(pipefd, filefd, pid);
	return (0);
}
