/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwintgen <rwintgen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 14:28:16 by amalangi          #+#    #+#             */
/*   Updated: 2024/04/26 18:30:26 by rwintgen         ###   ########.fr       */
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
	while (input[i])
	{
		if (input[i] == '|' && !is_between_quotes(input, &input[i])
			&& (!ft_isalnum(input[i + 1]) && input[i + 1] != ' '))
			return (err_msg_syntax(E_SYNTAX_PIPE, true));
		if (is_special_char(input[i]) && empty_line(input + i + 1))
			return (err_msg_syntax(E_SYNTAX_NL, true));
		if (is_too_many_redir(input) || wrong_count(input))
			return (err_msg_syntax(E_SYNTAX_REDIR, true));
		i++;
	}
	return (false);
}
