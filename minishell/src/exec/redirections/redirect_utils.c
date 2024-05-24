/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwintgen <rwintgen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 12:05:24 by rwintgen          #+#    #+#             */
/*   Updated: 2024/05/24 14:33:29 by rwintgen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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

// prints error message if file can't be opened
void	err_msg_file(char *infile)
{
	if (errno == EACCES)
		print_err(E_FILE_PERM, infile, NULL, NULL);
	else if (errno == ENOENT)
		print_err(E_FILE_EXIST, infile, NULL, NULL);
	else
		print_err(E_FILE_OPEN, infile, NULL, NULL);
}
