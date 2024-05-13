/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwintgen <rwintgen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 12:50:26 by rwintgen          #+#    #+#             */
/*   Updated: 2024/05/13 18:01:44 by rwintgen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

////////// BEHAVIOR ///////////
/*
export with no args
prints all env vars sorted
even if VALUE = NULL

export with KEY=VALUE
creates new env var
or updates existing with VALUE

export with KEY=
creates new env var
or updates existing with VALUE = ""

export with KEY
creates new env var with VALUE = NULL

export with =VALUE is an error
*/

// TODO segfaults

// minishell $> export a=value
// minishell $> export a

// minishell $> export a
// minishell $> unset a
// minishell $> export

int	ft_export(t_cmd *cmd, t_envp **envp)
{
	int		i;
	int		exit_code;
	char	*key;
	char	*value;

	i = 1;
	exit_code = 0;
	if (!cmd->cmd_and_args[i])
	{
		print_export(*envp);
		reset_export(*envp);
		return (0);
	}
	while (cmd->cmd_and_args[i])
	{
		key = get_key(cmd->cmd_and_args[i]);
		if (is_invalid_key(key))
		{
			free(key);
			exit_code = 1;
			err_msg_export(cmd->cmd_and_args[i]);
			i++;
			continue ;
		}
		value = get_value(cmd->cmd_and_args[i]);
		update_envp(envp, key, value);
		free(value);
		free(key);
		i++;
	}
	return (exit_code);
}

void	update_envp(t_envp **envp, char *key, char *new_value)
{
	t_envp	*tmp;

	tmp = *envp;
	while (tmp)
	{
		if (strcmp(tmp->key, key) == 0)
		{
			free(tmp->value);
			tmp->value = ft_strdup(new_value);
			return ;
		}
		tmp = tmp->next;
	}
	add_envp(envp, key, new_value);
}

void	init_new(t_envp *new, char *key, char *value)
{
	new->key = ft_strdup(key);
	new->value = NULL;
	if (value)
		new->value = ft_strdup(value);
	new->envar = NULL;
	new->next = NULL;
	new->prev = NULL;
	new->is_printed = false;
}

void	add_envp(t_envp **envp, char *key, char *value)
{
	t_envp	*new;
	t_envp	*tmp;

	new = malloc(sizeof(t_envp));
	if (!new)
	{
		ft_putendl_fd(E_MALLOC, STDERR_FILENO);
		return ;
	}
	init_new(new, key, value);
	tmp = *envp;
	if (tmp)
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
		new->prev = tmp;
	}
	else
		*envp = new;
}
