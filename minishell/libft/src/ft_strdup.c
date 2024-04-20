/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalangi <amalangi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 05:08:51 by amalangi          #+#    #+#             */
/*   Updated: 2023/11/02 05:37:42 by amalangi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *source)
{
	unsigned char	*ptr;
	size_t			i;

	ptr = malloc((ft_strlen(source) + 1) * sizeof(char));
	if (ptr)
	{
		i = 0;
		while (i < ft_strlen(source))
		{
			ptr[i] = source[i];
			i++;
		}
		ptr[i] = '\0';
	}
	return ((char *)ptr);
}
