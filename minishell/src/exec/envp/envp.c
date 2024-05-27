/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   envp.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwintgen <rwintgen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 13:44:40 by deymons           #+#    #+#             */
/*   Updated: 2024/05/27 16:47:53 by rwintgen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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
	result = ft_calloc(i + 1, sizeof(char *)); // MALLOC PROTECT OK
	if (!result)
		return (NULL);
	envp = head;
	i = 0;
	while (envp->next)
	{
		result[i] = ft_strdup(envp->envar); // MALLOC PROTECT OK
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
