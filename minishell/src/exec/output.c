/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwintgen <rwintgen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 16:08:10 by deymons           #+#    #+#             */
/*   Updated: 2024/04/22 16:44:39 by rwintgen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

/*
Output priority order:
1 - writes to last outfile
	> outfile cmd / cmd > outfile
2 - writes to pipe if no outfile, pipe
	cmd 1 | cmd 2
3 - writes to stdout if no outfile, no pipe
	cmd 
*/

bool	check_outf_outfile(t_arg *cmd, t_arg **true_outfile)
{
	int	fd;

	fd = -1;
	go_to_start_of_block(&cmd);
	while (cmd && cmd->type != PIPE)
	{
		if (cmd->type == OUTFILE)
		{
			if (cmd->prev->type == OUTPUT)
				ft_open(cmd->str_command, &fd, FLAG_WRITE);
			else if (cmd->prev->type == APPEND)
				ft_open(cmd->str_command, &fd, FLAG_APPEND);
			if (fd == -1)
			{
				ft_putstr_fd("minishell: permission denied: ", STDERR_FILENO);
				ft_putendl_fd(cmd->str_command, STDERR_FILENO);
				return (false);
			}
			close(fd);
			*true_outfile = cmd;
		}
		cmd = cmd->next;
	}
	return (true);
}

void	check_outf_pipe(t_arg *cmd, t_arg **true_outfile)
{
	go_to_start_of_block(&cmd);
	while (cmd)
	{
		if (!(*true_outfile) && cmd && cmd->type == PIPE)
			*true_outfile = cmd;
		cmd = cmd->next;
	}
}

int	set_outf_fd(t_arg	*true_outfile, int pfd_out, int stdfd_out)
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
