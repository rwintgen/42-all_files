/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_input_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwintgen <rwintgen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 12:22:55 by rwintgen          #+#    #+#             */
/*   Updated: 2024/05/14 14:18:00 by rwintgen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// checks if a character is quoted
int	is_quoted(char *input, char *c)
{
	int	i;
	int	sq_count;
	int	dq_count;

	i = 0;
	sq_count = 0;
	dq_count = 0;
	while (input[i] && &input[i] != c)
	{
		if (input[i] == '\'')
			sq_count++;
		else if (input[i] == '"')
			dq_count++;
		i++;
	}
	if (sq_count % 2 != 0)
		return (1);
	if (dq_count % 2 != 0)
		return (2);
	return (0);
}

// checks if a pipe is followed by a valid character
bool	check_pipe(char *input, int i)
{
	if (input[i] == '|' && !is_quoted(input, &input[i]))
	{
		i++;
		if (input[i] && input[i] != ' '
			&& !ft_isalnum(input[i]) && !is_special_char(input[i]))
			return (false);
		while (input[i] && input[i] == ' ')
			i++;
		if (input[i] == '|')
			return (false);
	}
	return (true);
}

// checks if a redirection is followed by a valid character
bool	check_redir(char *input, int i)
{
	int	redir_len;

	redir_len = 0;
	if (is_special_symbol(&input[i]) == -1 && !is_quoted(input, &input[i]))
		return (false);
	if (is_special_symbol(&input[i]) == REDIR && !is_quoted(input, &input[i]))
	{
		while (is_special_char(input[i]))
		{
			redir_len++;
			if (redir_len > 2)
				return (false);
			i++;
		}
		while (input[i] && input[i] == ' ')
			i++;
		if (is_special_char(input[i]))
			return (false);
	}
	return (true);
}

// checks for empty command line
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
