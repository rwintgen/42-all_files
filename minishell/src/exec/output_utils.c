/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwintgen <rwintgen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 12:32:46 by deymons           #+#    #+#             */
/*   Updated: 2024/04/22 16:44:22 by rwintgen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

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

// checks if cmd is the last output redirection
bool	last_outf(t_arg *cmd)
{
	t_arg	*last_outf;

	last_outf = cmd;
	while (last_outf->next)
		last_outf = last_outf->next;
	while (last_outf && !(last_outf->type == OUTPUT || last_outf->type == APPEND))
		last_outf = last_outf->prev;
	if (cmd == last_outf)
		return (true);
	return (false);
}

// creates all outfiles
void	create_outfiles(t_arg *cmd)
{
	int			fd;

	while (cmd && !last_outf(cmd))
	{
		fd = -1;
		if (cmd->type == OUTFILE && cmd->prev->type == OUTPUT)
			ft_open(cmd->str_command, &fd, FLAG_WRITE);
		else if (cmd->type == OUTFILE && cmd->prev->type == APPEND)
			ft_open(cmd->str_command, &fd, FLAG_APPEND);
		if (fd != -1)
			close(fd);
		cmd = cmd->next;
	}
}
