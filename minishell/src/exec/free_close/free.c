/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwintgen <rwintgen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 13:45:29 by deymons           #+#    #+#             */
/*   Updated: 2024/05/14 13:35:11 by rwintgen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// frees the sh struct
int	free_sh(t_sh *sh)
{
	int	exit_code;

	free_arg(sh->arg);
	free_cmd(sh->cmd);
	free_envp(sh->envp);
	free(sh);
	exit_code = set_exit_code(errno);
	return (exit_code);
}

// frees the arg linked list
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

// frees the cmd linked list
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

// frees the envp linked list
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
