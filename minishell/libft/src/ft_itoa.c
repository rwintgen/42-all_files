/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalangi <amalangi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 10:47:48 by amalangi          #+#    #+#             */
/*   Updated: 2023/11/05 05:23:11 by amalangi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	get_nb_size(int nb)
{
	int	size;

	size = 1;
	if (nb < 0)
		size++;
	while (nb / 10)
	{
		size++;
		nb /= 10;
	}
	return (size);
}

char	*ft_itoa(int n)
{
	int			size;
	int			i;
	char		*ptr;
	long int	nb;

	nb = n;
	size = get_nb_size(n) - 1;
	ptr = malloc((size + 2) * sizeof(char));
	if (!ptr)
		return (NULL);
	ptr[size + 1] = '\0';
	i = 0;
	if (nb < 0)
	{
		nb *= -1;
		ptr[0] = '-';
		i++;
	}
	while (size >= i)
	{
		ptr[size] = (nb % 10) + 48;
		nb = nb / 10;
		size--;
	}
	return (ptr);
}
