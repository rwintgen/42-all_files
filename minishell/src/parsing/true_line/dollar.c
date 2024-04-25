/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dollar.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwintgen <rwintgen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 15:38:25 by amalangi          #+#    #+#             */
/*   Updated: 2024/04/25 18:15:29 by rwintgen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*get_var(char *key, t_envp *envp)
{
	char	*envp_key;
	int		i;

	while (envp)
	{
		i = 0;
		while (envp->envar[i] && envp->envar[i] != '=')
			i++;
		envp_key = ft_substr(envp->envar, 0, i);
		if (ft_strncmp(envp_key, &key[1], ft_strlen(key)) == 0)
		{
			free(envp_key);
			return (envp->envar + i + 1);
		}
		free(envp_key);
		envp = envp->next;
	}
	return (NULL);
}

int	get_key_len(char *input, int i)
{
	int		key_len;

	key_len = 1;
	while (input[i + key_len] && ft_isalnum(input[i + key_len]))
		key_len++;
	return (key_len);
}

char	*var_replace(char *input, int *i, t_envp *envp, int exit_code)
{
	int		key_len;
	char	*key;
	char	*var;

	if (input[*i + 1] == '?')
	{
		input = ft_strrep(input, "$?", ft_itoa(exit_code));
		*i += 1;
	}
	else
	{
		key_len = get_key_len(input, *i);
		key = ft_substr(input, *i, key_len);
		var = get_var(key, envp);
		if (var)
			input = ft_strrep(input, key, var);
		else
			input = ft_strrep(input, key, "");
		*i += key_len;
	}
	return (input);
}

char	*var_expand(char *input, t_envp *envp, int exit_code)
{
	int		i;

	i = 0;
	while (input[i])
	{
		if (input[i] == '\'')
		{
			i++;
			while (input[i] && input[i] != '\'')
				i++;
		}
		else if (input[i] == '$')
			input = var_replace(input, &i, envp, exit_code);
		i++;
	}
	return (input);
}
