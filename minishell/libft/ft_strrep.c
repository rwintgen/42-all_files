/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrep.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwintgen <rwintgen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 16:43:40 by rwintgen          #+#    #+#             */
/*   Updated: 2024/05/30 14:32:03 by rwintgen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	in_sq(char *str, int i)
{
	int	sq;
	int	dq;
	int	j;

	sq = 0;
	dq = 0;
	j = 0;
	while (j < i)
	{
		if (str[j] == '\'' && !dq)
			sq = !sq;
		if (str[j] == '"' && !sq)
			dq = !dq;
		j++;
	}
	return (sq);
}

static char	*find_torep_start(char *str, char *torep)
{
	size_t	len;
	size_t	torep_len;
	int		i;

	len = ft_strlen(str);
	torep_len = ft_strlen(torep);
	i = 0;
	while (str[i] && (i + torep_len <= len))
	{
		if (!ft_strncmp(&str[i], torep, torep_len) && !in_sq(str, i))
			return (&str[i]);
		i++;
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

	if (!ft_strncmp(torep, "$", 2) && !ft_strncmp(repby, "", 1))
		return (str);
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
