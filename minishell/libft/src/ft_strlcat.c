/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalangi <amalangi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 18:02:34 by amalangi          #+#    #+#             */
/*   Updated: 2024/03/10 16:49:46 by amalangi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	length_src;
	size_t	length_dest;
	size_t	i;

	if ((!dest || !src) && size == 0)
		return (0);
	length_src = ft_strlen(src);
	length_dest = ft_strlen(dest);
	i = 0;
	if (length_dest < size - 1 && size > 0)
	{
		while (length_dest + i < size - 1 && i < length_src)
		{
			dest[length_dest + i] = src[i];
			i++;
		}
		dest[length_dest + i] = '\0';
	}
	if (length_dest >= size)
		length_dest = size;
	return (length_dest + length_src);
}
