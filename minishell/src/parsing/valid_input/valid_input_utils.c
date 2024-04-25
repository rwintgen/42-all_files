/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_input_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwintgen <rwintgen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 12:22:55 by rwintgen          #+#    #+#             */
/*   Updated: 2024/04/25 15:57:38 by rwintgen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

bool	is_too_many_redir(char *input)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (input[i])
	{
		if ((input[i] == '<' || input[i] == '>')
			&& !is_between_quotes(input, &input[i]))
		{
			count++;
			if (count > 2)
			{
				ft_putendl_fd(E_SYNTAX_REDIR, STDERR_FILENO);
				return (true);
			}
		}
		else
			count = 0;
		i++;
	}
	return (false);
}

bool	is_between_quotes(char *input, char *c)
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
	if (sq_count % 2 != 0 || dq_count % 2 != 0)
		return (true);
	return (false);
}
