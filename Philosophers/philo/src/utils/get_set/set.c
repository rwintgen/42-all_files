/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwintgen <rwintgen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 13:37:16 by rwintgen          #+#    #+#             */
/*   Updated: 2024/06/20 16:27:44 by rwintgen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// sets the value of a bool
void	set_bool(pthread_mutex_t *mutex, bool *var, bool value)
{
	mutex_action(mutex, LOCK);
	*var = value;
	mutex_action(mutex, UNLOCK);
}

// sets the value of a long
void	set_long(pthread_mutex_t *mutex, long *var, long value)
{
	mutex_action(mutex, LOCK);
	*var = value;
	mutex_action(mutex, UNLOCK);
}

// increments a long
void	increment_long(pthread_mutex_t *mutex, long *var)
{
	mutex_action(mutex, LOCK);
	(*var)++;
	mutex_action(mutex, UNLOCK);
}

