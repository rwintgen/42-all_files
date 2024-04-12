/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwintgen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 13:46:36 by rwintgen          #+#    #+#             */
/*   Updated: 2023/10/09 17:38:04 by rwintgen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	length;
	int	i;
	int	*arr;

	length = max - min;
	i = 0;
	if (min >= max)
	{
		*range = NULL;
		return (0);
	}
	arr = malloc(sizeof(int) * length);
	if (arr == NULL)
		return (-1);
	while (i < length)
	{
		arr[i] = min;
		min++;
		i++;
	}
	*range = arr;
	return (i);
}
