/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalangi <amalangi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 20:18:01 by amalangi          #+#    #+#             */
/*   Updated: 2023/11/07 01:29:32 by amalangi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *string, int searchedChar)
{
	size_t	length;

	length = ft_strlen(string);
	while (length > 0)
	{
		if (string[length] == (char)searchedChar)
			return ((char *)&string[length]);
		length--;
	}
	if (string[length] == (char)searchedChar)
		return ((char *)&string[length]);
	return (0);
}
