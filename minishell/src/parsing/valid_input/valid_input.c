/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwintgen <rwintgen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 14:28:16 by amalangi          #+#    #+#             */
/*   Updated: 2024/05/27 16:07:32 by rwintgen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static bool	open_quote(char *input);
static bool	syntax_error(char *input);
static int	err_msg_syntax(char *msg, int ret);

// checks that command line entered is valid
bool	valid_input(char *input, t_sh *sh)
{
	if (empty_line(input))
	{
		free(input);
		return (false);
	}
	if (open_quote(input) || syntax_error(input))
	{
		sh->exit_code = 2;
		add_history(input);
		free(input);
		return (false);
	}
	add_history(input);
	return (true);
}

// checks for open quotes in command line
static bool	open_quote(char *input)
{
	int		i;
	char	quote;

	i = 0;
	while (input[i])
	{
		if (input[i] == '\'' || input[i] == '"')
		{
			quote = input[i];
			i++;
			while (input[i] && input[i] != quote)
				i++;
			if (!input[i])
			{
				ft_putendl_fd(E_SYNTAX_QUOTE, STDERR_FILENO);
				return (true);
			}
		}
		i++;
	}
	return (false);
}

// checks for syntax errors in command line
static bool	syntax_error(char *input)
{
	int	i;

	i = 0;
	while (input[i] && input[i] == ' ')
		i++;
	if (input[i] == '|')
		return (err_msg_syntax(E_SYNTAX_PIPE, true));
	while (input[i])
	{
		if (!check_pipe(input, i))
			return (err_msg_syntax(E_SYNTAX_PIPE, true));
		if (is_special_char(input[i]) && empty_line(input + i + 1))
			return (err_msg_syntax(E_SYNTAX_NL, true));
		if (is_special_char(input[i]) && !check_redir(input, i))
			return (err_msg_syntax(E_SYNTAX_REDIR, true));
		i++;
	}
	return (false);
}

// prints an error message and returns the given return value
static int	err_msg_syntax(char *msg, int ret)
{
	ft_putendl_fd(msg, STDERR_FILENO);
	return (ret);
}
