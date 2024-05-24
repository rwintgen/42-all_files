/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_creat_no_cmd.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwintgen <rwintgen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 16:34:04 by rwintgen          #+#    #+#             */
/*   Updated: 2024/05/24 14:30:21 by rwintgen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	create_files_if_needed(t_arg *arg, int cmd_count, int file_count);
static int	create_files(t_arg *arg);

// handles file creation
int	check_file_creation(t_arg *arg)
{
	t_arg	*tmp;
	int		cmd_count;
	int		file_count;

	tmp = arg;
	cmd_count = 0;
	file_count = 0;
	while (tmp)
	{
		if (tmp->type == CMD)
			cmd_count++;
		if (tmp->type == OUTFILE || tmp->type == INFILE)
			file_count++;
		if (!tmp->next || tmp->type == PIPE)
		{
			if (create_files_if_needed(tmp, cmd_count, file_count) == ERROR)
				return (ERROR);
			tmp = tmp->next;
			cmd_count = 0;
			file_count = 0;
			continue ;
		}
		tmp = tmp->next;
	}
	return (SUCCESS);
}

// handle files creation that have no command associated
static int	create_files_if_needed(t_arg *arg, int cmd_count, int file_count)
{
	if (cmd_count == 0 && file_count > 0)
	{
		if (create_files(arg) == ERROR)
			return (ERROR);
	}
	return (SUCCESS);
}

// creates files
static int	create_files(t_arg *arg)
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
			print_err(E_FILE_EXIST, arg->str_command, NULL, NULL);
			return (fd);
		}
		arg = arg->next;
	}
	return (fd);
}
