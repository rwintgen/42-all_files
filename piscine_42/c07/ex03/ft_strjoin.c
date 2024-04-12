/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwintgen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 15:51:09 by rwintgen          #+#    #+#             */
/*   Updated: 2023/10/09 17:38:30 by rwintgen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != 0)
		i++;
	return (i);
}

int	ft_combsize(int size, char **strs, char *sep)
{
	int	i;
	int	combsize;

	i = 0;
	combsize = 0;
	while (i < size)
	{
		combsize = combsize + ft_strlen(strs[i]);
		i++;
	}
	if (size > 0)
		combsize += ft_strlen(sep) * size -1;
	return (combsize);
}

char	*ft_strcat(char *dest, char *src)
{
	int	isrc;
	int	idest;

	idest = ft_strlen(dest);
	isrc = 0;
	while (src[isrc] != '\0')
	{
		dest[idest + isrc] = src[isrc];
		isrc++;
	}
	dest[idest + isrc] = '\0';
	return (dest);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		i;
	int		combsize;
	char	*dest;

	combsize = ft_combsize(size, strs, sep);
	if (size > 0)
		combsize += ft_strlen(sep) * size -1;
	dest = malloc(sizeof(char) * (combsize + 1));
	i = 0;
	while (i < size)
	{
		ft_strcat(dest, strs[i]);
		if (i < size - 1)
			ft_strcat(dest, sep);
		i++;
	}
	dest[combsize] = '\0';
	return (dest);
}
