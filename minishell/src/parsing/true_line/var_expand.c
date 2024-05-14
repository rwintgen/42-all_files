/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   var_expand.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwintgen <rwintgen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 15:38:25 by amalangi          #+#    #+#             */
/*   Updated: 2024/05/14 12:57:28 by rwintgen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// if the variable should be expanded
bool	is_valid_var(char *input, int dollar)
{
	int	sq;
	int	dq;
	int	i;

	sq = 0;
	dq = 0;
	i = 0;
	while (input[i] && i < dollar)
	{
		if (input[i] == '\'' && !dq)
			sq = !sq;
		if (input[i] == '"' && !sq)
			dq = !dq;
		i++;
	}
	if (sq)
		return (false);
	return (true);
}

// handles variable expansion 
char	*var_expand(char *input, t_envp *envp, int exit_code)
{
	int	i;
	int	len;

	len = ft_strlen(input);
	i = 0;
	while (input[i])
	{
		if (input[i] == '$' && is_valid_var(input, i))
			input = var_replace(input, &i, envp, exit_code);
		if (i < len - 1)
			i++;
		else
			break ;
	}
	return (input);
}

// replaces the variable with its value
char	*var_replace(char *input, int *i, t_envp *envp, int exit_code)
{
	int		key_len;
	char	*key;
	char	*value;
	char	*tmp;

	if (input[*i + 1] == '?')
	{
		tmp = ft_itoa(exit_code);
		input = ft_strrep(input, "$?", tmp);
		free(tmp);
		*i += 1;
	}
	else if (isalnum(input[*i + 1]) || input[*i + 1] == '_')
	{
		key_len = get_key_len(input, *i);
		key = ft_substr(input, *i, key_len);
		value = find_value(key, envp);
		if (value)
			input = ft_strrep(input, key, value);
		else
			input = ft_strrep(input, key, "");
		*i += key_len;
	}
	return (input);
}

// finds value associated with key
char	*find_value(char *key, t_envp *envp)
{
	while (envp)
	{
		if (!ft_strcmp(envp->key, key + 1))
			return (envp->value);
		envp = envp->next;
	}
	return (NULL);
}
