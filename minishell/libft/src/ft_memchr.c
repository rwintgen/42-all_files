/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalangi <amalangi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 20:35:13 by amalangi          #+#    #+#             */
/*   Updated: 2023/11/07 01:28:15 by amalangi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *memoryBlock, int searchedChar, size_t size)
{
	size_t	i;
	char	*ptr;

	ptr = (char *)memoryBlock;
	i = 0;
	while (i < size)
	{
		if (ptr[i] == (char)searchedChar)
			return (&ptr[i]);
		i++;
	}
	return (NULL);
}
