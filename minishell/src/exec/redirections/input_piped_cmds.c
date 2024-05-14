/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_piped_cmds.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwintgen <rwintgen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 18:52:36 by rwintgen          #+#    #+#             */
/*   Updated: 2024/05/14 13:47:00 by rwintgen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static bool	cat_piped(int stdfd_in, int fd, t_arg *cmd);
static bool	grep_piped(int stdfd_in, int fd, t_arg *cmd);
static bool	wc_piped(int stdfd_in, int fd, t_arg *cmd);

// changes fd's value if cat, grep or wc waits for input
void	check_input_piped_cmds(int *fd, t_arg *arg, int stdfd_in)
{
	if (cat_piped(stdfd_in, *fd, arg))
		*fd = -2;
	else if (grep_piped(stdfd_in, *fd, arg))
		*fd = -3;
	else if (wc_piped(stdfd_in, *fd, arg))
		*fd = -4;
}

// checks if cat waits for input
static bool	cat_piped(int stdfd_in, int fd, t_arg *cmd)
{
	t_arg	*tmp;

	tmp = cmd;
	if (ft_strcmp(cmd->str_command, "cat") || fd != stdfd_in)
		return (false);
	while (tmp && tmp->type != PIPE)
		tmp = tmp->prev;
	if (!tmp)
		return (false);
	return (true);
}

// checks if grep waits for input
static bool	grep_piped(int stdfd_in, int fd, t_arg *cmd)
{
	t_arg	*tmp;

	tmp = cmd;
	if (ft_strcmp(cmd->str_command, "grep") || fd != stdfd_in)
		return (false);
	if (!cmd->next || cmd->next->type != ARG)
		return (false);
	while (tmp && tmp->type != PIPE)
		tmp = tmp->prev;
	if (!tmp)
		return (false);
	return (true);
}

// checks if wc waits for input
static bool	wc_piped(int stdfd_in, int fd, t_arg *cmd)
{
	t_arg	*tmp;

	tmp = cmd;
	if (ft_strcmp(cmd->str_command, "wc") || fd != stdfd_in)
		return (false);
	while (tmp && tmp->type != PIPE)
		tmp = tmp->prev;
	if (!tmp)
		return (false);
	return (true);
}
