/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwintgen <rwintgen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 16:08:10 by deymons           #+#    #+#             */
/*   Updated: 2024/05/14 15:40:08 by rwintgen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
Output priority order:
1 - writes to last outfile
	> outfile cmd / cmd > outfile
2 - writes to pipe if no outfile, pipe
	cmd 1 | cmd 2
3 - writes to stdout if no outfile, no pipe
	cmd 
*/

static int	set_outf_fd(t_arg	*true_outfile, int pfd_out, int stdfd_out);

// finds right outfile and opens it for current cmd
int	set_outfile(t_arg *cmd, int stdfd_out, int pipefd_out)
{
	int		fd;
	t_arg	*true_outfile;

	true_outfile = NULL;
	if (count_redir_out(cmd) > 1)
		create_outfiles(cmd);
	if (!check_outf_outfile(cmd, &true_outfile))
		return (ERROR);
	if (pipefd_out != -1)
		check_outf_pipe(cmd, &true_outfile);
	fd = set_outf_fd(true_outfile, pipefd_out, stdfd_out);
	return (fd);
}

// opens outfile and returns its FD
static int	set_outf_fd(t_arg	*true_outfile, int pfd_out, int stdfd_out)
{
	int	fd;

	fd = 0;
	if (true_outfile && true_outfile->type == OUTFILE)
	{
		if (true_outfile->prev->type == OUTPUT)
			ft_open(true_outfile->str_command, &fd, FLAG_WRITE);
		if (true_outfile->prev->type == APPEND)
			ft_open(true_outfile->str_command, &fd, FLAG_APPEND);
	}
	else if (true_outfile && true_outfile->type == PIPE)
		fd = pfd_out;
	else if (!true_outfile)
		fd = stdfd_out;
	return (fd);
}
