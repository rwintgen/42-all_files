/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   var_expand_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwintgen <rwintgen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 12:41:14 by rwintgen          #+#    #+#             */
/*   Updated: 2024/05/29 17:16:23 by rwintgen         ###   ########.fr       */
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
	while (str[i] && is_whitespace(str[i]))
		i--;
	if (str[i] && str[i] == '<' && str[i - 1] && str[i - 1] == '<')
		return (true);
	return (false);
}
