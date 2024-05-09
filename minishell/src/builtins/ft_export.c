/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwintgen <rwintgen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 12:50:26 by rwintgen          #+#    #+#             */
/*   Updated: 2024/05/09 15:18:48 by rwintgen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

////////// BEHAVIOR ///////////
/*
export with no args prints
all env vars sorted
even if VALUE = NULL

export with KEY=VALUE
creates new env var or updates existing
with VALUE

export with KEY=
creates new env var or updates existing
with VALUE = ""

export with KEY
creates new env var with VALUE = NULL

export with =VALUE is an error
*/

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
	new->key = ft_strdup(key);
	new->value = NULL;
	if (new->value)
		new->value = ft_strdup(value);
	new->envar = NULL;
	new->next = NULL;
	new->prev = NULL;
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
