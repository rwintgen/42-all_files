/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwintgen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 15:09:33 by rwintgen          #+#    #+#             */
/*   Updated: 2023/11/07 13:13:06 by rwintgen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t n)
{
	size_t	i;
	size_t	y;

	i = 0;
	if ((!big || !little) && n == 0)
		return (NULL);
	if (!*little)
		return ((char *)big);
	while (big[i] && i < n)
	{
		y = 0;
		while (little[y] == big[i + y] && i + y < n)
		{
			if (!little[y + 1])
				return ((char *)&big[i]);
			y++;
		}
		i++;
	}
	return (NULL);
}
