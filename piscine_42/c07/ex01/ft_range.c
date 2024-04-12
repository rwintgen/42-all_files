/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwintgen <rwintgen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 15:33:51 by rwintgen          #+#    #+#             */
/*   Updated: 2023/10/09 17:37:27 by rwintgen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	*arr;
	int	length;
	int	i;

	length = max - min;
	i = 0;
	if (min >= max)
	{
		arr = NULL;
		return (arr);
	}
	arr = malloc(sizeof(int) * length);
	if (arr == NULL)
		return (arr);
	while (i < length)
	{
		arr[i] = min;
		min++;
		i++;
	}
	return (arr);
}
