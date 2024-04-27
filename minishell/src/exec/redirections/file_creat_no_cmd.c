/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_creat_no_cmd.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwintgen <rwintgen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 16:34:04 by rwintgen          #+#    #+#             */
/*   Updated: 2024/04/27 16:34:10 by rwintgen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	create_files(t_arg *arg)
{
	int	fd;

	go_to_start_of_block(&arg);
	while (arg && arg->type != PIPE)
	{
		fd = -2;
		if (arg->type == OUTFILE)
			ft_open(arg->str_command, &fd, FLAG_WRITE);
		else if (arg->type == INFILE)
			ft_open(arg->str_command, &fd, FLAG_READ);
		close_if_valid(fd);
		if (fd == -1)
		{
			ft_putstr_fd(E_FILE_EXIST, STDERR_FILENO);
			ft_putendl_fd(arg->str_command, STDERR_FILENO);
			return (fd);
		}
		arg = arg->next;
	}
	return (fd);
}

int	check_file_creation(t_arg *arg)
{
	t_arg	*tmp;
	int		cmd_count;
	int		file_count;

	tmp = arg;
	cmd_count = 0;
	while (tmp)
	{
		if (tmp->type == CMD)
			cmd_count++;
		if (tmp->type == OUTFILE || tmp->type == INFILE)
			file_count++;
		if (tmp->type == PIPE || tmp->next == NULL)
		{
			if (cmd_count == 0 && file_count > 0)
			{
				if (create_files(tmp) == -1)
					return (-1);
			}
			tmp = tmp->next;
			cmd_count = 0;
			file_count = 0;
			continue ;
		}
		tmp = tmp->next;
	}
	return (0);
}