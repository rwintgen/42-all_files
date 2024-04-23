/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwintgen <rwintgen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 14:28:16 by amalangi          #+#    #+#             */
/*   Updated: 2024/04/23 12:37:33 by rwintgen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

int	open_quote(char *input)
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
		ft_putstr_fd("minishell: open quote\n", STDERR_FILENO);
		return (true);
	}
	return (false);
}

int	empty_line(char *input)
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
