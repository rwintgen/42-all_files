/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwintgen <rwintgen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 16:07:33 by deymons           #+#    #+#             */
/*   Updated: 2024/04/23 12:21:46 by rwintgen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

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

// finds right infile and opens it for current cmd
int	set_infile(t_arg *cmd, int stdfd_in, int pipefd_in)
{
	int		fd;
	t_arg	*true_infile;
	char	*heredoc_file;

	heredoc_file = NULL;
	true_infile = NULL;
	go_to_start_of_block(&cmd);
	if (!infiles_ok(cmd))
		return (-1);
	if (pipefd_in != -1)
		check_inf_pipe(cmd->prev, &true_infile);
	while (cmd && cmd->type != PIPE)
	{
		if (!check_inf_delim(cmd, &heredoc_file))
			check_inf_infile(cmd, &true_infile);
		cmd = cmd->next;
	}
	fd = set_inf_fd(heredoc_file, true_infile, pipefd_in, stdfd_in);
	// TODO check if below lines are necessary
	if ((heredoc_file || !true_infile || true_infile->type != PIPE) && pipefd_in != -1)
		close(pipefd_in);
	return (fd);
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

// checks if all infiles exist and have correct permissions
bool	infiles_ok(t_arg *cmd)
{
	int	fd;
	// TODO check exit code diff between unexisting/no-perm files

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
