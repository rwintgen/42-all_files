/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwintgen <rwintgen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 14:28:16 by amalangi          #+#    #+#             */
/*   Updated: 2024/04/28 15:31:11 by rwintgen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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

bool	open_quote(char *input)
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

bool	empty_line(char *input)
{
	int	i;

	i = 0;
	while (input[i])
	{
		if (input[i] != ' '
			&& input[i] != '\t'
			&& input[i] != '\n'
			&& input[i] != '\v'
			&& input[i] != '\f'
			&& input[i] != '\r')
			return (false);
		i++;
	}
	return (true);
}

bool	syntax_error(char *input)
{
	int	i;

	i = 0;
	while (input[i] && input[i] == ' ')
		i++;
	if (input[i] == '|')
		return (err_msg_syntax(E_SYNTAX_PIPE, true));
	while (input[i])
	{
		// checks that non-quoted pipes are followed by alphanum characters
		if (!check_pipe(input, i))
			return (err_msg_syntax(E_SYNTAX_PIPE, true));
		// checks that non-quoted special characters are not at end of line
		if (is_special_char(input[i]) && empty_line(input + i + 1))
			return (err_msg_syntax(E_SYNTAX_NL, true));
		// checks that non quotes redirection symbols are valid
		if (is_special_char(input[i]) && !check_redir(input, i))
			return (err_msg_syntax(E_SYNTAX_REDIR, true));
		i++;
	}
	return (false);
}
