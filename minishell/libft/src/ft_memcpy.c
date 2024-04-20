/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalangi <amalangi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 19:31:14 by amalangi          #+#    #+#             */
/*   Updated: 2023/11/05 05:09:39 by amalangi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t size)
{
	unsigned int	i;
	unsigned char	*tmp;
	unsigned char	*tmp_to_cpy;

	if (!dst && !src)
		return (NULL);
	tmp = (unsigned char *)dst;
	tmp_to_cpy = (unsigned char *)src;
	i = 0;
	while (i < size)
	{
		tmp[i] = tmp_to_cpy[i];
		i++;
	}
	dst = (void *)tmp;
	return (dst);
}
