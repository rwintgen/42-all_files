/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwintgen <rwintgen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 16:11:44 by deymons           #+#    #+#             */
/*   Updated: 2024/04/27 16:45:41 by rwintgen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// returns current command index
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

// counts the number of commands
int	count_commands(t_cmd *cmd)
{
	int	count;

	count = 0;
	if (!cmd)
		return (0);
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

// forks and handles fork error
int	ft_fork(t_sh *sh)
{
	int	pid;

	pid = fork();
	if (pid == -1)
	{
		sh->cmd->skip_cmd = true;
		ft_putendl_fd(E_FORK, STDERR_FILENO);
		return (-1);
	}
	return (pid);
}

// waits for all children processes to finish
void	ft_wait_all(void)
{
	int	status;

	while (wait(&status) > 0)
	{
	}
}
