/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwintgen <rwintgen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 12:50:26 by rwintgen          #+#    #+#             */
/*   Updated: 2024/05/02 13:15:45 by rwintgen         ###   ########.fr       */
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

int	ft_export(t_cmd *cmd, t_envp *envp)
{
	int		i;
	char	*key;
	char	*value;

	i = 1;
	if (!cmd->cmd_and_args[i])
	{
		print_export(envp);
		reset_export(envp);
		return (0);
	}
	while (cmd->cmd_and_args[i])
	{
		key = get_key(cmd->cmd_and_args[i]);
		if (is_invalid_key(key))
		{
			err_msg_export(cmd->cmd_and_args[i]);
			i++;
			continue ;
		}
		value = get_value(cmd->cmd_and_args[i]);
		update_envp(envp, key, value);
		i++;
	}
	return (0);
}

void	update_envp(t_envp *envp, char *key, char *new_value)
{
	t_envp	*tmp;

	tmp = envp;
	while (tmp)
	{
		if (!ft_strncmp(tmp->key, key, ft_strlen(key)))
		{
			free(tmp->value);
			tmp->value = new_value;
			return ;
		}
		tmp = tmp->next;
	}
	add_envp(envp, key, new_value);
}

void	add_envp(t_envp *envp, char *key, char *value)
{
	t_envp	*new;
	t_envp	*tmp;

	new = malloc(sizeof(t_envp));
	new->key = key;
	new->value = value;
	new->next = NULL;
	new->prev = NULL;
	tmp = envp;
	if (tmp)
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
		new->prev = tmp;
	}
	else
		envp = new;
}
