/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwintgen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 14:26:37 by rwintgen          #+#    #+#             */
/*   Updated: 2023/11/11 15:36:39 by rwintgen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_intlen(long int n)
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

char	*ft_itoa(int n)
{
	char	*dest;
	int		len;
	int		sign;
	long	ln;

	ln = n;
	sign = n;
	len = ft_intlen(ln);
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
	if (sign < 0)
		dest[0] = '-';
	return (dest);
}
