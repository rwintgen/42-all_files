/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwintgen <rwintgen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 16:07:33 by deymons           #+#    #+#             */
/*   Updated: 2024/04/20 13:46:56 by rwintgen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

/*
Input priority order:
1 - reads from heredoc if heredoc
	<< EOF cmd / cmd << EOF
2 - reads from infile if infile
	< infile cmd / cmd < infile
3 - reads from pipe if no heredoc, pipe
	cmd 1 | cmd 2
4 - reads from stdin if no infile, no heredoc
	cmd 1
*/

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

bool	infiles_ok(t_arg *cmd)
{
	int fd;

	while (cmd && cmd->type != PIPE)
	{
		fd = -1;
		if (cmd->type == INFILE)
		{
			if (ft_open(cmd->str_command, &fd, FLAG_READ) < 0)
			{
				ft_putstr_fd("minishell: permission denied: ", STDERR_FILENO);
				ft_putendl_fd(cmd->str_command, STDERR_FILENO);
				return (false);
			}
		}
		if (fd != -1)
			close(fd);
		cmd = cmd->next;
	}
	return (true);
}

int	prev_cmd_out(t_arg *cmd)
{
	while (cmd && cmd->type != PIPE)
		cmd = cmd->prev;
	if (cmd && cmd->type == PIPE && cmd->prev)
		cmd = cmd->prev;
	while (cmd && cmd->type != PIPE)
	{
		if (cmd->type == OUTFILE)
			return (1);
		cmd = cmd->prev;
	}
	return (0);
}

void	go_to_start_of_block(t_arg **cmd)
{
	while (*cmd && (*cmd)->prev && (*cmd)->prev->type != PIPE)
		*cmd = (*cmd)->prev;
}

void	check_inf_pipe(t_arg *to_check, t_arg **true_infile)
{
	if (to_check && to_check->type == PIPE && !prev_cmd_out(to_check))
		*true_infile = to_check;
}

int	check_inf_delim(t_arg *to_check, char **heredoc_file)
{
	if (to_check && to_check->type == DELIM)
	{
		*heredoc_file = heredoc_handler(to_check->str_command);
		return (1);
	}
	return (0);
}

void	check_inf_infile(t_arg *to_check, t_arg **true_infile)
{
	if (to_check && to_check->type == INFILE)
		*true_infile = to_check;
}

// returns the right fd for the infile
int	set_inf_fd(char *hd_file, t_arg *true_infile, int pfd_in, int stdfd_in)
{
	int	fd;

	fd = -1;
	if (hd_file)
		ft_open(hd_file, &fd, FLAG_READ);
	else if (true_infile && true_infile->type == INFILE)
		ft_open(true_infile->str_command, &fd, FLAG_READ);
	else if (true_infile && true_infile->type == PIPE)
		fd = pfd_in;
	else if (!true_infile)
		fd = stdfd_in;
	return (fd);
}