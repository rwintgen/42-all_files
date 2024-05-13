/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   envp.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwintgen <rwintgen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 13:44:40 by deymons           #+#    #+#             */
/*   Updated: 2024/05/13 18:46:42 by rwintgen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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
