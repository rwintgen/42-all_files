/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwintgen <rwintgen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 12:50:26 by rwintgen          #+#    #+#             */
/*   Updated: 2024/04/29 14:42:31 by rwintgen         ###   ########.fr       */
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

int	err_msg_export(char *arg)
{
	ft_putstr_fd(E_EXPORT_ID, STDERR_FILENO);
	ft_putendl_fd(arg, STDERR_FILENO);
	return (1);
}

bool	is_invalid_key(char *key)
{
	int	i;

	i = 0;
	if (!key || !key[0])
		return (true);
	if (key[0] && !ft_isalpha(key[0]) && key[0] != '_')
		return (true);
	while (key[i])
	{
		if (!ft_isalnum(key[i]) && key[i] != '_')
			return (true);
		i++;
	}
	return (false);
}

int	ft_export(t_cmd *cmd, t_envp *envp)
{
	int		i;
	char	*key;
	char	*value;

	i = 1;
	if (!cmd->cmd_and_args[i])
	{
		print_export(envp);
		return (0);
	}
	while (cmd->cmd_and_args[i])
	{
		key = get_key(cmd->cmd_and_args[i]);
		if (is_invalid_key(key))
			return (err_msg_export(cmd->cmd_and_args[i]));
		value = get_value(cmd->cmd_and_args[i]);
		update_envp(envp, key, value);
		i++;
	}
	return (0);
}

void	print_export(t_envp *envp)
{
	t_envp	*tmp;

	tmp = envp;
	while (tmp)
	{
		ft_putstr_fd("declare -x ", STDOUT_FILENO);
		ft_putstr_fd(tmp->key, STDOUT_FILENO);
		if (tmp->value)
		{
			ft_putstr_fd("=\"", STDOUT_FILENO);
			ft_putstr_fd(tmp->value, 1);
			ft_putstr_fd("\"\n", STDOUT_FILENO);
		}
		else
			ft_putstr_fd("\n", STDOUT_FILENO);
		tmp = tmp->next;
	}
}

char	*get_key(char *arg)
{
	int		i;
	char	*key;

	i = 0;
	while (arg[i] && arg[i] != '=')
		i++;
	key = ft_substr(arg, 0, i);
	return (key);
}

char	*get_value(char *arg)
{
	int		i;
	char	*value;

	i = 0;
	while (arg[i] && arg[i] != '=')
		i++;
	if (!arg[i])
		return (NULL);
	value = ft_strdup(arg + i + 1);
	return (value);
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
