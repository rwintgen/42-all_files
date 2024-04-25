/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   true_line_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwintgen <rwintgen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 13:19:51 by rwintgen          #+#    #+#             */
/*   Updated: 2024/04/25 14:56:39 by rwintgen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

// counts the amount of missing spaces in input
int	count_missing_spaces(char *str)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (is_special_char(str[i]))
		{
			count += missing_space_before(str, i);
			count += missing_space_after(str, i);
		}
		i++;
	}
	return (count);
}

// checks if there is a missing space before a special character
bool	missing_space_before(char *str, int i)
{
	if (i == 0)
		return (false);
	if (str[i - 1] != ' ' && !is_special_char(str[i - 1])
		&& str[i - 1] != '\'' && str[i - 1] != '\"')
		return (true);
	return (false);
}

// checks if there is a missing space after a special character
bool	missing_space_after(char *str, int i)
{
	if (str[i + 1] == '\0')
		return (false);
	if (str[i + 1] != ' ' && !is_special_char(str[i + 1])
		&& str[i + 1] != '\'' && str[i + 1] != '\"')
		return (true);
	if (is_special_char(str[i + 1]) && str[i] != str[i + 1])
		return (true);
	return (false);
}
