/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalangi <amalangi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 21:05:08 by amalangi          #+#    #+#             */
/*   Updated: 2023/11/05 05:11:35 by amalangi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *string, const char *to_search, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if ((!string || !to_search) && len == 0)
		return (0);
	if (to_search[i] == 0)
		return ((char *)string);
	while (string[i] != '\0' && i < len)
	{
		if (string[i] == to_search[0])
		{
			j = 0;
			while (string[i + j] == to_search[j] && to_search[j])
				j++;
			if (to_search[j] == '\0' && i + j <= len)
				return ((char *)&string[i]);
		}
		i++;
	}
	return (0);
}
