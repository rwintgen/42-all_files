/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwintgen <rwintgen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 13:47:42 by deymons           #+#    #+#             */
/*   Updated: 2024/04/23 12:22:05 by rwintgen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

// redirects input and output and closes all FDs
void	redirect_io(t_cmd *cmd)
{
	dup2(cmd->input_fd, STDIN_FILENO);
	dup2(cmd->output_fd, STDOUT_FILENO);
	close_all_fds();
}

// redirects input and output for non-forked cmd
void	redirect_io_nofork(t_sh *sh, t_cmd *cmd)
{
	dup2(cmd->input_fd, STDIN_FILENO);
	dup2(cmd->output_fd, STDOUT_FILENO);
	if (cmd->input_fd != sh->saved_stdfd[0])
		close_if_valid(cmd->input_fd);
	if (cmd->output_fd != sh->saved_stdfd[1])
		close_if_valid(cmd->output_fd);
}

// restores input and output for non-forked cmd
void	restore_io_nofork(t_sh *sh, t_cmd *cmd)
{
	dup2(sh->saved_stdfd[0], STDIN_FILENO);
	dup2(sh->saved_stdfd[1], STDOUT_FILENO);
	if (cmd->input_fd != sh->saved_stdfd[0])
		close_if_valid(cmd->input_fd);
	if (cmd->output_fd != sh->saved_stdfd[1])
		close_if_valid(cmd->output_fd);
}
