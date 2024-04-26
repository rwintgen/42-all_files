/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrep.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwintgen <rwintgen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 16:43:40 by rwintgen          #+#    #+#             */
/*   Updated: 2024/04/26 13:06:55 by rwintgen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*find_torep_start(char *str, char *torep)
{
	char	*current;
	int		in_quotes;
	size_t	len;
	size_t	torep_len;

	current = str;
	in_quotes = 0;
	len = ft_strlen(str);
	torep_len = ft_strlen(torep);
	while (*current && (current - str + torep_len <= len))
	{
		if (*current == '\'')
		{
			in_quotes = !in_quotes;
			current++;
			continue ;
		}
		if (!in_quotes && ft_strncmp(current, torep, torep_len) == 0)
			return (current);
		current++;
	}
	return (NULL);
}

static int	getlen(char *str, char *torep, char *repby)
{
	unsigned int	orig_len;
	unsigned int	torep_len;
	unsigned int	repby_len;
	unsigned int	result_len;

	orig_len = ft_strlen(str);
	torep_len = ft_strlen(torep);
	repby_len = ft_strlen(repby);
	result_len = orig_len - torep_len + repby_len;
	return (result_len);
}

char	*ft_strrep(char *str, char *torep, char *repby)
{
	char	*result;
	char	*start;
	int		result_len;

	start = find_torep_start(str, torep);
	if (!start)
		return (NULL);
	result_len = getlen(str, torep, repby);
	result = malloc(result_len + 1);
	if (!result)
		return (NULL);
	ft_strlcpy(result, str, start - str + 1);
	ft_strlcat(result, repby, result_len + 1);
	ft_strlcat(result, start + ft_strlen(torep), result_len + 1);
	return (result);
}
