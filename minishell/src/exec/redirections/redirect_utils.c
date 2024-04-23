/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwintgen <rwintgen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 12:05:24 by rwintgen          #+#    #+#             */
/*   Updated: 2024/04/23 13:05:34 by rwintgen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

// opens the fd in the correct mode
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

// saves STDIN and STDOUT fds
void	save_stdfd(int saved_stdfd[2])
{
	int	stdin_fd;
	int	stdout_fd;

	stdin_fd = STDIN_FILENO;
	stdout_fd = STDOUT_FILENO;
	saved_stdfd[0] = dup(stdin_fd);
	saved_stdfd[1] = dup(stdout_fd);
}

// set the cmd ptr to the start of the block
void	go_to_start_of_block(t_arg **cmd)
{
	while (*cmd && (*cmd)->prev && (*cmd)->prev->type != PIPE)
		*cmd = (*cmd)->prev;
}

// exits if one on cmd's FD is invalid
void	check_valid_fds(t_sh *sh)
{
	if (sh->cmd->input_fd < 0)
	{
		close_all_fds();
		exit(free_sh(sh));
	}
	else if (sh->cmd->output_fd < 0)
	{
		close_all_fds();
		exit(free_sh(sh));
	}
}
