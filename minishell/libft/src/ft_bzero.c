/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalangi <amalangi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 19:22:32 by amalangi          #+#    #+#             */
/*   Updated: 2023/11/02 05:06:27 by amalangi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *ptr, size_t size)
{
	unsigned int	i;
	unsigned char	*tmp;

	tmp = (unsigned char *)ptr;
	i = 0;
	while (i < size)
	{
		tmp[i] = 0;
		i++;
	}
}
