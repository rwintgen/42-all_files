/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwintgen <rwintgen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 16:11:44 by deymons           #+#    #+#             */
/*   Updated: 2024/04/22 16:26:15 by rwintgen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	current_command(t_cmd *cmd)
{
	t_cmd	*current;
	int		i;

	current = cmd;
	i = 0;
	while (cmd->prev)
		cmd = cmd->prev;
	while (cmd && cmd != current)
	{
		i++;
		cmd = cmd->next;
	}
	printf("current command: %s, number %d\n", current->cmd_and_args[0], i);
	return (i);
}

int	count_commands(t_cmd *cmd)
{
	int	count;

	count = 0;
	while (cmd->prev)
		cmd = cmd->prev;
	while (cmd)
	{
		count++;
		cmd = cmd->next;
	}
	return (count);
}

// checks if arg is last cmd
int	last_cmd(t_arg *arg)
{
	t_arg	*current;

	current = arg;
	while (arg->next)
		arg = arg->next;
	while (arg->prev && arg->type != CMD)
		arg = arg->prev;
	if (arg == current)
		return (true);
	return (false);
}

bool	is_builtin(char *cmd)
{
	if (!ft_strncmp(cmd, "echo", 5)
		|| !ft_strncmp(cmd, "cd", 3)
		|| !ft_strncmp(cmd, "pwd", 4)
		|| !ft_strncmp(cmd, "export", 7)
		|| !ft_strncmp(cmd, "unset", 6)
		|| !ft_strncmp(cmd, "env", 4)
		|| !ft_strncmp(cmd, "exit", 5))
		return (true);
	return (false);
}
