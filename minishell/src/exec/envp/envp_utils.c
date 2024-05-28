/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   envp_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwintgen <rwintgen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 18:43:54 by rwintgen          #+#    #+#             */
/*   Updated: 2024/05/27 17:37:19 by rwintgen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	init_new_envp_node(t_envp *new_node, char *env_var);

// appends a new node to the envp linked list
void	append_env_node(t_envp **env_cpy, char *env_var, t_sh *tofree)
{
	t_envp	*new_node;
	t_envp	*tmp;

	new_node = ft_calloc(1, sizeof(t_envp));
	if (!new_node)
	{
		ft_putendl_fd(E_MALLOC, STDERR_FILENO);
		free_sh(tofree);
		close_all_fds();
		exit(EXIT_FAILURE);
	}
	init_new_envp_node(new_node, env_var);
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

// inits new envp node's variables
static void	init_new_envp_node(t_envp *new_node, char *env_var)
{
	new_node->envar = ft_strdup(env_var);
	new_node->key = NULL;
	new_node->value = NULL;
	new_node->is_printed = false;
	new_node->next = NULL;
	new_node->prev = NULL;
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
		if (!ft_strcmp(tmp->envar, env_var))
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
		if (!ft_strcmp(tmp->envar, env_var))
		{
			free(tmp->value);
			tmp->value = value;
			break ;
		}
		tmp = tmp->next;
	}
}

// counts the number of envp variables
int	count_vars(t_envp *envp)
{
	int	i;

	i = 0;
	while (envp)
	{
		i++;
		envp = envp->next;
	}
	return (i);
}
