/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_close.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwintgen <rwintgen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 13:45:29 by deymons           #+#    #+#             */
/*   Updated: 2024/04/22 15:11:53 by rwintgen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	free_sh(t_sh *sh)
{
	int	exit_code;

	// memory freeing
	free_arg(sh->arg);
	free_cmd(sh->cmd);
	free_envp(sh->envp);
	free(sh);

	// exit code setting
	printf("errno: %d\n\n", errno);
	exit_code = set_exit_code(errno);
	return (exit_code);
}

void	free_arg(t_arg *arg)
{
	t_arg	*tmp;

	while (arg && arg->prev)
		arg = arg->prev;
	while (arg)
	{
		tmp = arg;
		arg = arg->next;
		free(tmp->str_command);
		free(tmp);
	}
}

void	free_cmd(t_cmd *cmd)
{
	t_cmd	*tmp;
	
	while (cmd && cmd->prev)
		cmd = cmd->prev;
	while (cmd)
	{
		tmp = cmd;
		cmd = cmd->next;
		ft_free_char_tab(tmp->cmd_and_args);
		free(tmp);
	}
}

void	free_envp(t_envp *envp)
{
	t_envp	*tmp;

	while (envp && envp->prev)
		envp = envp->prev;
	while (envp)
	{
		tmp = envp;
		envp = envp->next;
		free(tmp->envar);
		free(tmp->key);
		free(tmp->value);
		free(tmp);
	}
}

void	close_if_valid(int fd)
{
	if (fd > 0)
		close(fd);
}

void	close_all_fds(t_cmd *cmd)
{
	t_cmd	*current;

	current = cmd;
	while (current && current->prev)
		current = current->prev;
	while (current)
	{
		close_if_valid(current->input_fd);
		close_if_valid(current->output_fd);
		current = current->next;
	}
}

void	close_saved_fds(int saved_stdfd[2])
{
	close(saved_stdfd[0]);
	close(saved_stdfd[1]);
}
	