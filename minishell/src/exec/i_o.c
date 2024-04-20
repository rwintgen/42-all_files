/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   i_o.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwintgen <rwintgen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 13:47:42 by deymons           #+#    #+#             */
/*   Updated: 2024/04/20 11:30:25 by rwintgen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	ft_open(char *file, int *fd, int flag)
{
	if (flag == FLAG_READ)
		*fd = open(file, O_RDONLY);
	else if (flag == FLAG_HEREDOC)
		*fd = open(file, O_CREAT | O_WRONLY | O_APPEND, 0644);
	else if (flag == FLAG_WRITE)
		*fd = open(file, O_CREAT | O_TRUNC | O_WRONLY, 0644);
	else if (flag == FLAG_APPEND)
		*fd = open(file, O_CREAT | O_APPEND | O_RDWR, 0644);
	else if (flag == FLAG_TMP)
		*fd = open(file, O_CREAT | O_EXCL | O_WRONLY, 0777);
	return (*fd);
}

// opens and assigns all FDs
void save_stdfd(int saved_stdfd[2])
{
	int stdin_fd;
	int	stdout_fd;

	stdin_fd = STDIN_FILENO;
	stdout_fd = STDOUT_FILENO;
	saved_stdfd[0] = dup(stdin_fd);
	saved_stdfd[1] = dup(stdout_fd);
}

void	redirect_io(t_cmd *cmd)
{
	dup2(cmd->input_fd, STDIN_FILENO);
	dup2(cmd->output_fd, STDOUT_FILENO);
	close_all_fds(cmd);
}

// finds right infile and opens it for current cmd
int	set_infile(t_arg *cmd, int stdfd_in, int pipefd_in)
{
	int			fd;
	t_arg	*true_infile;
	char		*heredoc_file;

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
	if ((heredoc_file || !true_infile || true_infile->type != PIPE) && pipefd_in != -1)
		close(pipefd_in);
	return (fd);
}

int	set_outfile(t_arg *cmd, int stdfd_out, int pipefd_out)
{
	int			fd;
	t_arg	*true_outfile;

	true_outfile = NULL;
	if (count_redir_out(cmd) > 1)
		create_outfiles(cmd);
	if (!check_outf_outfile(cmd, &true_outfile))
		return (-1);
	if (pipefd_out != -1)
		check_outf_pipe(cmd, &true_outfile);
	fd = set_outf_fd(true_outfile, pipefd_out, stdfd_out);
	if ((!true_outfile || true_outfile->type != PIPE) && pipefd_out != -1)
		close(pipefd_out);
	return (fd);
}
