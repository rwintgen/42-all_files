/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwintgen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 18:40:11 by rwintgen          #+#    #+#             */
/*   Updated: 2023/11/11 12:05:50 by rwintgen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	srclen;

	i = 0;
	j = 0;
	srclen = ft_strlen(src);
	if (size == 0)
		return (srclen);
	while (i < size && dst[i])
		i++;
	while (i + j < size - 1 && src[j])
	{
		dst[i + j] = src[j];
		j++;
	}
	if (j)
		dst[i + j] = '\0';
	return (i + srclen);
}
