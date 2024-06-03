/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   var_expand_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwintgen <rwintgen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 12:41:14 by rwintgen          #+#    #+#             */
/*   Updated: 2024/05/30 18:00:43 by rwintgen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// replaces exit code for $?
char	*replace_exit_code(char *input, int *i, int exit_code)
{
	char	*exit_code_str;

	if (g_sig == SIGINT || g_sig == 130)
		exit_code = 130;
	exit_code_str = ft_itoa(exit_code);
	input = ft_strrep(input, "$?", exit_code_str);
	*i += 1 - ft_strlen(exit_code_str);
	free(exit_code_str);
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

// checks if $KEY is a heredoc delimiter
bool	is_hd_delimiter(char *str, int i)
{
	if (i > 0)
		i--;
	while (i > 0 && str[i] && is_whitespace(str[i]))
		i--;
	if (str[i] && str[i] == '<' && str[i - 1] && str[i - 1] == '<')
		return (true);
	return (false);
}

// replaces variable in input with its value
char	*replace_var_with_value(char *input, int *i, t_envp *envp)
{
	int		key_len;
	char	*key;
	char	*value;

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
	return (input);
}
