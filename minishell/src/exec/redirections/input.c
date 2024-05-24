/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwintgen <rwintgen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 16:07:33 by deymons           #+#    #+#             */
/*   Updated: 2024/05/24 15:58:43 by rwintgen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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

static int	hd_check(t_arg *cmd, t_sh *tofree, t_arg **infile, char **file);
static int	set_inf_fd(char *hd_file, t_arg *infile, int pfd_in, int stdfd_in);
static bool	infiles_ok(t_arg *cmd);

// finds right infile and opens it for current cmd
int	set_infile(t_arg *cmd, int stdfd_in, int pipefd_in, t_sh *tofree)
{
	t_arg	*infile;
	t_arg	*tmp;
	char	*heredoc_file;
	int		fd;

	heredoc_file = NULL;
	infile = NULL;
	tmp = cmd;
	go_to_start_of_block(&cmd);
	if (!infiles_ok(cmd))
		return (ERROR);
	if (pipefd_in != -1)
		check_inf_pipe(cmd->prev, &infile);
	while (cmd && cmd->type != PIPE)
	{
		hd_check(cmd, tofree, &infile, &heredoc_file);
		cmd = cmd->next;
	}
	fd = set_inf_fd(heredoc_file, infile, pipefd_in, stdfd_in);
	check_input_piped_cmds(&fd, tmp, stdfd_in);
	unlink_heredoc_file(heredoc_file);
	return (fd);
}

static int	hd_check(t_arg *cmd, t_sh *tofree, t_arg **infile, char **file)
{
	int	ret;

	ret = check_inf_delim(cmd, file, tofree);
	if (!ret)
		check_inf_infile(cmd, infile);
	return (ret);
}

// returns the right fd for the infile
static int	set_inf_fd(char *hd_file, t_arg *infile, int pfd_in, int stdfd_in)
{
	int	fd;

	fd = -1;
	if (hd_file)
		ft_open(hd_file, &fd, FLAG_READ);
	else if (infile && infile->type == INFILE)
		ft_open(infile->str_command, &fd, FLAG_READ);
	else if (infile && infile->type == PIPE)
		fd = pfd_in;
	else if (!infile)
		fd = stdfd_in;
	return (fd);
}

// checks if all infiles exist and have correct permissions
static bool	infiles_ok(t_arg *cmd)
{
	int	fd;

	while (cmd && cmd->type != PIPE)
	{
		fd = -1;
		if (cmd->type == INFILE)
		{
			if (ft_open(cmd->str_command, &fd, FLAG_READ) < 0)
			{
				err_msg_file(cmd->str_command);
				return (false);
			}
		}
		if (fd != -1)
			close(fd);
		cmd = cmd->next;
	}
	return (true);
}
