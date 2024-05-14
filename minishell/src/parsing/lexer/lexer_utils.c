/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwintgen <rwintgen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 04:28:32 by amalangi          #+#    #+#             */
/*   Updated: 2024/05/14 10:24:56 by rwintgen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// returns char type
int	is_special_char(char c)
{
	if (c == '|')
		return (PIPE);
	if (c == '>' || c == '<')
		return (REDIR);
	return (SUCCESS);
}

// returns 1 if word is pipe, 2 if redirection, 0 if neither
int	is_special_symbol(char *c)
{
	int	i;

	i = 0;
	while (c[i] && is_special_char(c[i]) && c[i] != ' ')
	{
		if (i > 0 && c[i] != c[i - 1]
			&& !is_quoted(c, &c[i]) && c[i - 1] != '|')
			return (-1);
		i++;
	}
	return (is_special_char(c[0]));
}
