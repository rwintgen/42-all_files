/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalangi <amalangi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 09:33:33 by amalangi          #+#    #+#             */
/*   Updated: 2023/11/02 02:54:46 by amalangi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove( void *dest, const void *src, size_t size )
{
	int	i;

	if (dest > src && dest - src < (int)size)
	{
		i = (int)size - 1;
		while (i >= 0)
		{
			*(char *)(dest + i) = *(char *)(src + i);
			i--;
		}
		return (dest);
	}
	if (src > dest && src - dest < (int)size)
	{
		i = 0;
		while (i < (int)size)
		{
			*(char *)(dest + i) = *(char *)(src + i);
			i++;
		}
		return (dest);
	}
	return (ft_memcpy(dest, src, size));
}
