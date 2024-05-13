/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwintgen <rwintgen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 12:00:07 by rwintgen          #+#    #+#             */
/*   Updated: 2024/05/13 13:30:44 by rwintgen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// checks if cmd is the last input redirection
bool	last_inf(t_arg *cmd)
{
	t_arg	*last_inf;

	last_inf = cmd;
	while (last_inf->next)
		last_inf = last_inf->next;
	while (last_inf && last_inf->prev && last_inf->type != INFILE)
		last_inf = last_inf->prev;
	if (cmd == last_inf)
		return (true);
	return (false);
}

// checks if previous command has an output redirection
bool	prev_cmd_out(t_arg *cmd)
{
	while (cmd && cmd->type != PIPE)
		cmd = cmd->prev;
	if (cmd && cmd->type == PIPE && cmd->prev)
		cmd = cmd->prev;
	while (cmd && cmd->type != PIPE)
	{
		if (cmd->type == OUTFILE)
			return (true);
		cmd = cmd->prev;
	}
	return (false);
}

// checks if current cmd has a pipe input redirection
void	check_inf_pipe(t_arg *to_check, t_arg **true_infile)
{
	if (to_check && to_check->type == PIPE && !prev_cmd_out(to_check))
		*true_infile = to_check;
}

// checks if current cmd has a heredoc redirection
bool	check_inf_delim(t_arg *to_check, char **heredoc_file, t_sh *sh)
{
	if (to_check && to_check->type == DELIM)
	{
		*heredoc_file = heredoc_handler(to_check->str_command, sh);
		return (true);
	}
	return (false);
}

// checks if current cmd has an infile redirection
void	check_inf_infile(t_arg *to_check, t_arg **true_infile)
{
	if (to_check && to_check->type == INFILE)
		*true_infile = to_check;
}
