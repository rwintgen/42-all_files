/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwintgen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 15:48:09 by rwintgen          #+#    #+#             */
/*   Updated: 2023/11/06 13:30:29 by rwintgen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*start;

	if (nmemb && size && nmemb > (4294967295 / size))
		return (NULL);
	start = malloc(nmemb * size);
	if (!start)
		return (start);
	ft_bzero(start, nmemb * size);
	return (start);
}
