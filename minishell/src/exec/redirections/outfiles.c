/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   outfiles.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwintgen <rwintgen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 19:08:12 by rwintgen          #+#    #+#             */
/*   Updated: 2024/05/14 15:39:45 by rwintgen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// opens current outfile
int	open_outfile(t_arg *cmd, int *fd)
{
	if (cmd->prev->type == OUTPUT)
		ft_open(cmd->str_command, fd, FLAG_WRITE);
	else if (cmd->prev->type == APPEND)
		ft_open(cmd->str_command, fd, FLAG_APPEND);
	if (*fd == -1)
	{
		err_msg_file(cmd->str_command);
		return (FAILURE);
	}
	close(*fd);
	return (SUCCESS);
}

// creates all outfiles
void	create_outfiles(t_arg *cmd)
{
	int	fd;
	int	fd_in;

	fd_in = -2;
	go_to_start_of_block(&cmd);
	while (cmd && !last_outf(cmd))
	{
		fd = -1;
		if (cmd->type == INFILE)
			ft_open(cmd->str_command, &fd_in, FLAG_READ);
		if (fd_in == -1)
			return ;
		else if (cmd->type == OUTFILE && cmd->prev->type == OUTPUT)
			ft_open(cmd->str_command, &fd, FLAG_WRITE);
		else if (cmd->type == OUTFILE && cmd->prev->type == APPEND)
			ft_open(cmd->str_command, &fd, FLAG_APPEND);
		if (fd != -1)
			close(fd);
		else
			return ;
		cmd = cmd->next;
	}
}
