/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwintgen <rwintgen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 13:37:16 by rwintgen          #+#    #+#             */
/*   Updated: 2024/05/23 13:38:15 by rwintgen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	set_bool(t_mutex *mutex, bool *var, bool value)
{
	mutex_action(mutex, LOCK);
	*var = value;
	mutex_action(mutex, UNLOCK);
}

void	set_long(t_mutex *mutex, long *var, long value)
{
	mutex_action(mutex, LOCK);
	*var = value;
	mutex_action(mutex, UNLOCK);
}

void	increment_long(t_mutex *mutex, long *var)
{
	mutex_action(mutex, LOCK);
	*var += 1;
	mutex_action(mutex, UNLOCK);
}

