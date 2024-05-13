/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwintgen <rwintgen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 12:32:46 by deymons           #+#    #+#             */
/*   Updated: 2024/05/13 19:14:42 by rwintgen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// counts number of output redirections in cmd
int	count_redir_out(t_arg *cmd)
{
	int	count;

	count = 0;
	while (cmd)
	{
		if (cmd->type == OUTPUT || cmd->type == APPEND)
			count++;
		cmd = cmd->next;
	}
	return (count);
}

// checks if current cmd has a pipe output redirection
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

// checks if current cmd has an outfile redirection
bool	check_outf_outfile(t_arg *cmd, t_arg **true_outfile)
{
	int	fd;
	int	fd_in;

	fd = -1;
	fd_in = -2;
	go_to_start_of_block(&cmd);
	while (cmd && cmd->type != PIPE)
	{
		if (cmd->type == INFILE)
			ft_open(cmd->str_command, &fd_in, FLAG_READ);
		if (fd_in == -1)
			return (true);
		if (cmd->type == OUTFILE)
		{
			if (open_outfile(cmd, &fd) == 1)
				return (false);
			*true_outfile = cmd;
		}
		cmd = cmd->next;
	}
	return (true);
}

// checks if cmd is the last output redirection
bool	last_outf(t_arg *cmd)
{
	t_arg	*last_outf;

	last_outf = cmd;
	while (last_outf->next)
		last_outf = last_outf->next;
	while (last_outf && !(last_outf->type == OUTPUT
			|| last_outf->type == APPEND))
		last_outf = last_outf->prev;
	if (cmd == last_outf)
		return (true);
	return (false);
}
