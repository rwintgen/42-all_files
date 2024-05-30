/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   envp.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwintgen <rwintgen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 13:44:40 by deymons           #+#    #+#             */
/*   Updated: 2024/05/30 17:51:28 by rwintgen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	create_envp(t_envp **envp);

// converts a char **envp to a t_envp linked list
t_envp	*save_envp(char **env, t_sh *tofree)
{
	t_envp	*env_cpy;
	int		i;

	env_cpy = NULL;
	i = 0;
	while (env[i])
	{
		append_env_node(&env_cpy, env[i], tofree);
		set_key(&env_cpy, env[i]);
		set_value(&env_cpy, env[i]);
		i++;
	}
	if (i == 0)
		create_envp(&env_cpy);
	return (env_cpy);
}

// restores envp to a char ** format
char	**restore_envp(t_envp *envp)
{
	t_envp	*head;
	char	**result;
	int		i;

	head = envp;
	i = count_vars(envp);
	result = ft_calloc(i + 1, sizeof(char *));
	if (!result)
		return (NULL);
	envp = head;
	i = 0;
	while (envp->next)
	{
		result[i] = ft_strdup(envp->envar);
		if (!result[i])
		{
			ft_free_char_tab(result);
			return (NULL);
		}
		i++;
		envp = envp->next;
	}
	result[i] = NULL;
	return (result);
}

static void	create_envp(t_envp **envp)
{
	t_envp	*new_node;
	t_envp	*oldpwd_node;

	new_node = malloc(sizeof(t_envp));
	if (!new_node)
		return ;
	new_node->key = ft_strdup("PWD");
	new_node->value = getcwd(NULL, 0);
	new_node->envar = assemble_envar(new_node->key, new_node->value);
	new_node->prev = NULL;
	new_node->next = NULL;
	*envp = new_node;
	oldpwd_node = malloc(sizeof(t_envp));
	if (!oldpwd_node)
		return ;
	oldpwd_node->key = ft_strdup("OLDPWD");
	oldpwd_node->value = NULL;
	oldpwd_node->prev = *envp;
	oldpwd_node->next = NULL;
	(*envp)->next = oldpwd_node;
}
