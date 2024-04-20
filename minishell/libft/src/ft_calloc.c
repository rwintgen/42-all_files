/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalangi <amalangi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 23:02:48 by amalangi          #+#    #+#             */
/*   Updated: 2023/11/07 04:23:40 by amalangi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t elementCount, size_t elementSize)
{
	void	*ptr;

	if ((long long)elementCount < 0 || (long long)elementSize < 0)
	{
		if (((long long)elementCount < 0 && (long long)elementSize == 0)
			|| ((long long)elementCount == 0 && (long long)elementSize < 0))
			return (malloc(0));
		return (NULL);
	}
	ptr = malloc(elementCount * elementSize);
	if (ptr == NULL)
		return (ptr);
	ft_bzero(ptr, elementSize * elementCount);
	return (ptr);
}
