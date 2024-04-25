/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwintgen <rwintgen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 14:28:16 by amalangi          #+#    #+#             */
/*   Updated: 2024/04/25 14:46:36 by rwintgen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

bool	valid_input(char *input)
{
	if (empty_line(input) || open_quote(input) || syntax_error(input))
	{
		if (!empty_line(input))
			add_history(input);
		free(input);
		return (false);
	}
	add_history(input);
	return (true);
}

bool	open_quote(char *input)
{
	int	i;
	int	single_quote;
	int	double_quote;

	i = 0;
	single_quote = 0;
	double_quote = 0;
	while (input[i])
	{
		if (input[i] == 34)
			double_quote++;
		else if (input[i] == 39)
			single_quote++;
		i++;
	}
	if (single_quote % 2 != 0 || double_quote % 2 != 0)
	{
		ft_putendl_fd(E_SYNTAX_QUOTE, STDERR_FILENO);
		return (true);
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
		{
			ft_putendl_fd(E_SYNTAX_PIPE, STDERR_FILENO);
			return (true);
		}
		if (is_special_char(input[i]) && empty_line(input + i + 1))
		{
			ft_putendl_fd(E_SYNTAX_NL, STDERR_FILENO);
			return (true);
		}
		if (is_too_many_redir(input))
			return (true);
		i++;
	}
	return (false);
}
