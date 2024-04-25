/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_input_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwintgen <rwintgen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 12:22:55 by rwintgen          #+#    #+#             */
/*   Updated: 2024/04/25 12:34:09 by rwintgen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

bool	is_too_many_redir(char *input)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (input[i])
	{
		if (input[i] == '<' || input[i] == '>')
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
