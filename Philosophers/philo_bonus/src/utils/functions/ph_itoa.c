/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwintgen <rwintgen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 14:33:53 by rwintgen          #+#    #+#             */
/*   Updated: 2024/06/27 14:37:18 by rwintgen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

static size_t	ph_intlen(long int n)
{
	size_t	size;

	size = 1;
	if (n < 0)
	{
		size++;
		n *= -1;
	}
	while (n > 9)
	{
		n = n / 10;
		size++;
	}
	return (size);
}

char	*ph_itoa(int n)
{
	char	*dest;
	int		len;
	long	ln;

	ln = n;
	len = ph_intlen(ln);
	dest = malloc(sizeof(char) * (len + 1));
	if (!dest)
		return (NULL);
	if (ln < 0)
		ln = ln * -1;
	dest[len] = '\0';
	len--;
	while (len >= 0)
	{
		dest[len] = ln % 10 + '0';
		ln = ln / 10;
		len--;
	}
	if (n < 0)
		dest[0] = '-';
	return (dest);
}
