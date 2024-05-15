/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   var_expand.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwintgen <rwintgen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 15:38:25 by amalangi          #+#    #+#             */
/*   Updated: 2024/05/15 12:41:02 by rwintgen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static bool	is_valid_var(char *input, int dollar);
static char	*var_replace(char *input, int *i, t_envp *envp, int exit_code);
static char	*replace_exit_code(char *input, int *i, int exit_code);
static char	*find_value(char *key, t_envp *envp);

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

// if the variable should be expanded
static bool	is_valid_var(char *input, int dollar)
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
			input = ft_strrep(input, key, value);
		else
			input = ft_strrep(input, key, "");
		*i += key_len;
	}
	return (input);
}

static char	*replace_exit_code(char *input, int *i, int exit_code)
{
	char	*exit_code_str;

	if (g_sig == SIGINT)
		exit_code = 130;
	exit_code_str = ft_itoa(exit_code);
	input = ft_strrep(input, "$?", exit_code_str);
	free(exit_code_str);
	*i += 1;
	return (input);
}

// finds value associated with key
static char	*find_value(char *key, t_envp *envp)
{
	while (envp)
	{
		if (!ft_strcmp(envp->key, key + 1))
			return (envp->value);
		envp = envp->next;
	}
	return (NULL);
}
