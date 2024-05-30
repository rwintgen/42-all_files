/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwintgen <rwintgen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 12:50:26 by rwintgen          #+#    #+#             */
/*   Updated: 2024/05/30 15:21:14 by rwintgen         ###   ########.fr       */
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

static bool	check_key(char *key, t_cmd *cmd, int *i, int *exit_code);
static void	update_envp(t_envp **envp, char *key, char *new_value);
static void	add_envp(t_envp **envp, char *key, char *value);
static void	init_new_envp_node(t_envp *new, char *key, char *value);

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
		return (SUCCESS);
	}
	while (cmd->cmd_and_args[i])
	{
		key = get_key(cmd->cmd_and_args[i]);
		if (!check_key(key, cmd, &i, &exit_code))
			continue ;
		value = get_value(cmd->cmd_and_args[i]);
		update_envp(envp, key, value);
		free(value);
		free(key);
		i++;
	}
	return (exit_code);
}

static bool	check_key(char *key, t_cmd *cmd, int *i, int *exit_code)
{
	if (is_invalid_key(key))
	{
		free(key);
		*exit_code = 1;
		print_err(E_EXPORT_ID, cmd->cmd_and_args[*i], NULL, NULL);
		*i += 1;
		return (false);
	}
	return (true);
}

static void	update_envp(t_envp **envp, char *key, char *new_value)
{
	t_envp	*tmp;

	tmp = *envp;
	while (tmp)
	{
		if (!strcmp(tmp->key, key))
		{
			if (tmp->value && new_value)
				free(tmp->value);
			if (new_value)
				tmp->value = ft_strdup(new_value);
			return ;
		}
		tmp = tmp->next;
	}
	add_envp(envp, key, new_value);
}

static void	add_envp(t_envp **envp, char *key, char *value)
{
	t_envp	*new;
	t_envp	*tmp;

	new = malloc(sizeof(t_envp));
	if (!new)
	{
		ft_putendl_fd(E_MALLOC, STDERR_FILENO);
		return ;
	}
	init_new_envp_node(new, key, value);
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

static void	init_new_envp_node(t_envp *new, char *key, char *value)
{
	new->key = ft_strdup(key);
	new->value = NULL;
	if (value)
		new->value = ft_strdup(value);
	new->envar = assemble_envar(key, value);
	new->next = NULL;
	new->prev = NULL;
	new->is_printed = false;
}
