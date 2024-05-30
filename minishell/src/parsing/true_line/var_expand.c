/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   var_expand.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwintgen <rwintgen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 15:38:25 by amalangi          #+#    #+#             */
/*   Updated: 2024/05/30 15:54:30 by rwintgen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static bool	is_valid_var(char *input, int dollar);
static char	*var_replace(char *input, int *i, t_envp *envp, int exit_code);

// handles variable expansion 
char	*var_expand(char *input, t_envp *envp, int exit_code, int i)
{
	char	*result;

	if (i < 0)
		i = 0;
	if (!input)
		return (NULL);
	while (input[i])
	{
		if (input[i] == '$' && is_valid_var(input, i))
		{
			result = var_replace(input, &i, envp, exit_code);
			if (input != result)
				free(input);
			return (var_expand(result, envp, exit_code, i));
		}
		i++;
	}
	return (input);
}

// if the variable should be expanded
static bool	is_valid_var(char *input, int dollar)
{
	int	sq;
	int	dq;
	int	i;

	sq = 0;
	dq = 0;
	i = 0;
	if (!input[dollar + 1] || is_whitespace(input[dollar + 1]))
		return (false);
	if (is_hd_delimiter(input, dollar))
		return (false);
	while (input[i] && i < dollar)
	{
		if (input[i] == '\'' && !dq)
			sq = !sq;
		if (input[i] == '"' && !sq)
			dq = !dq;
		i++;
	}
	if (sq || (dq && input[dollar + 1] == '"'))
		return (false);
	return (true);
}

// replaces the variable with its value
static char	*var_replace(char *input, int *i, t_envp *envp, int exit_code)
{
	int		key_len;
	char	*key;
	char	*value;

	if (input[*i + 1] == '?')
		input = replace_exit_code(input, i, exit_code);
	else if (isalnum(input[*i + 1]) || input[*i + 1] == '_')
	{
		key_len = get_key_len(input, *i);
		key = ft_substr(input, *i, key_len);
		value = find_value(key, envp);
		if (value)
		{
			input = ft_strrep(input, key, value);
			*i += ft_strlen(value) - key_len;
		}
		else
		{
			input = ft_strrep(input, key, "");
			*i -= 1;
		}
		free(key);
	}
	else if (get_key_len(input, *i) == 1)
            input[*i] = ' ';
	return (input);
}
