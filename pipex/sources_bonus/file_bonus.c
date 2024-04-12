/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwintgen <rwintgen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 16:10:58 by rwintgen          #+#    #+#             */
/*   Updated: 2024/04/05 14:08:53 by rwintgen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex_bonus.h"

int	ft_open(char *file, int *fd, int flag)
{
	if (flag == FLAG_READ)
		*fd = open(file, O_RDONLY);
	else if (flag == FLAG_WRITE)
		*fd = open(file, O_CREAT | O_TRUNC | O_RDWR, 0644);
	else if (flag == FLAG_HEREDOC)
		*fd = open(file, O_CREAT | O_WRONLY | O_APPEND, 0644);
	return (*fd);
}

void	set_inf_outf_fds(int *filefd, int argc, char **argv, int arg_cursor)
{
	int	fd_inf;
	int	fd_outf;

	if (arg_cursor == 1)
	{
		fd_inf = ft_open(argv[arg_cursor], filefd, FLAG_READ);
		fd_outf = ft_open(argv[argc - 1], filefd + 1, FLAG_WRITE);
	}
	else
	{
		fd_inf = (*filefd);
		fd_outf = ft_open(argv[argc - 1], filefd + 1, FLAG_HEREDOC);
	}
	if (fd_inf < 0)
		err_msg(ERR_INFILE);
	if (fd_outf < 0)
	{
		close(filefd[0]);
		exit(err_msg(ERR_OUTFILE));
	}
	*filefd = fd_inf;
	*(filefd + 1) = fd_outf;
}
