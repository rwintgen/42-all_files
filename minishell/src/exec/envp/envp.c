/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   envp.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwintgen <rwintgen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 13:44:40 by deymons           #+#    #+#             */
/*   Updated: 2024/04/25 15:57:38 by rwintgen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// appends a new node to the envp linked list
void	append_env_node(t_envp **env_cpy, char *env_var)
{
	t_envp	*new_node;
	t_envp	*tmp;

	new_node = ft_calloc(1, sizeof(t_envp));
	if (!new_node)
	{
		ft_putendl_fd(E_MALLOC, STDERR_FILENO);
		// free_sh(sh);
		close_all_fds();
		exit(1);
	}
	new_node->envar = ft_strdup(env_var);
	new_node->key = NULL;
	new_node->value = NULL;
	new_node->next = NULL;
	new_node->prev = NULL;
	if (*env_cpy == NULL)
		*env_cpy = new_node;
	else
	{
		tmp = *env_cpy;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new_node;
		new_node->prev = tmp;
	}
}

// sets the key of the envp linked list
void	set_key(t_envp **env_cpy, char *env_var)
{
	t_envp	*tmp;
	char	*key;
	int		i;

	tmp = *env_cpy;
	i = 0;
	while (env_var[i] != '=')
		i++;
	key = ft_substr(env_var, 0, i);
	while (tmp)
	{
		if (ft_strncmp(tmp->envar, env_var, INT_MAX) == 0)
		{
			free(tmp->key);
			tmp->key = key;
			break ;
		}
		tmp = tmp->next;
	}
}

// sets the value of the envp node
void	set_value(t_envp **env_cpy, char *env_var)
{
	t_envp	*tmp;
	char	*value;
	int		i;

	tmp = *env_cpy;
	i = 0;
	while (env_var[i] != '=')
		i++;
	value = ft_substr(env_var, i + 1, ft_strlen(env_var) - i - 1);
	while (tmp)
	{
		if (ft_strncmp(tmp->envar, env_var, INT_MAX) == 0)
		{
			free(tmp->value);
			tmp->value = value;
			break ;
		}
		tmp = tmp->next;
	}
}

// converts a char **envp to a t_envp linked list
t_envp	*save_envp(char **env)
{
	t_envp	*env_cpy;
	int		i;

	env_cpy = NULL;
	i = 0;
	while (env[i])
	{
		append_env_node(&env_cpy, env[i]);
		set_key(&env_cpy, env[i]);
		set_value(&env_cpy, env[i]);
		i++;
	}
	return (env_cpy);
}

// restores envp to a char ** format
char	**restore_envp(t_envp *envp)
{
	t_envp	*head;
	char	**result;
	int		i;

	head = envp;
	i = 0;
	while (envp)
	{
		i++;
		envp = envp->next;
	}
	result = ft_calloc(i + 1, sizeof(char *));
	envp = head;
	i = 0;
	while (envp)
	{
		result[i] = ft_strdup(envp->envar);
		i++;
		envp = envp->next;
	}
	result[i] = NULL;
	return (result);
}
