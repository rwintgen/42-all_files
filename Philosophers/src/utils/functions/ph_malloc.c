/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_malloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwintgen <rwintgen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 12:08:14 by rwintgen          #+#    #+#             */
/*   Updated: 2024/05/22 12:08:29 by rwintgen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*ph_malloc(size_t size)
{
	void	*ptr;

	ptr = malloc(size);
	if (!ptr)
		err_exit(E_MALLOC, MSG_MALLOC);
	return (ptr);
}