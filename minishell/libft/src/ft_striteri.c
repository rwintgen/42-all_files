/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalangi <amalangi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 02:37:33 by amalangi          #+#    #+#             */
/*   Updated: 2023/11/08 13:06:29 by amalangi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	size_t	i;
	size_t	size;

	if (!(s == NULL || f == NULL))
	{
		i = 0;
		size = ft_strlen(s);
		while (i < size)
		{
			f(i, &s[i]);
			i++;
		}
	}
}
