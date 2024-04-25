/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwintgen <rwintgen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 04:28:32 by amalangi          #+#    #+#             */
/*   Updated: 2024/04/25 15:57:38 by rwintgen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_special_char(char c)
{
	if (c == '>' || c == '<' || c == '|')
		return (1);
	return (0);
}

int	contain_special_char(char *c)
{
	int	i;

	i = 0;
	while (c[i])
	{
		if (is_special_char(c[i]))
			return (1);
		i++;
	}
	return (0);
}
