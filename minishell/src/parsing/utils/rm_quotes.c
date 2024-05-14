/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rm_quotes.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwintgen <rwintgen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 15:50:10 by rwintgen          #+#    #+#             */
/*   Updated: 2024/05/14 14:09:52 by rwintgen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*ft_strdelchar(char *str, char c, unsigned int n);

// removes quotes from a string
void	remove_quote(char *str)
{
	int		i;
	char	q;
	char	*copy;

	i = 0;
	copy = str;
	while (copy[i])
	{
		if (copy[i] == '"' || copy[i] == '\'')
		{
			q = copy[i];
			i++;
			while (copy[i] && copy[i] != q)
				i++;
			ft_strdelchar(copy, q, 2);
			copy = copy + i - 1;
			i = 0;
			continue ;
		}
		i++;
	}
}

// removes a character from a string
static char	*ft_strdelchar(char *str, char c, unsigned int n)
{
	size_t	i;

	i = 0;
	if (!n)
		return (str);
	while (str[i])
	{
		if (str[i] == c)
		{
			while (str[i])
			{
				str[i] = str[i + 1];
				i++;
			}
			return (ft_strdelchar(str, c, n - 1));
		}
		i++;
	}
	return (str);
}
