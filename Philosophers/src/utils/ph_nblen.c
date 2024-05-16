/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_nblen.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwintgen <rwintgen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 14:24:38 by rwintgen          #+#    #+#             */
/*   Updated: 2024/05/16 16:24:41 by rwintgen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

size_t	ph_nblen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] && is_num(s[i]))
		i++;
	return (i);
}
