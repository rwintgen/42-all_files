/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_set.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwintgen <rwintgen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 14:25:53 by rwintgen          #+#    #+#             */
/*   Updated: 2024/05/22 16:10:46 by rwintgen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	set_bool(t_mutex *mutex, bool *var, bool value)
{
	mutex_action(mutex, LOCK);
	*var = value;
	mutex_action(mutex, UNLOCK);
}

bool	get_bool(t_mutex *mutex, bool *var)
{
	bool	value;

	mutex_action(mutex, LOCK);
	value = *var;
	mutex_action(mutex, UNLOCK);
	return (value);
}

void	set_long(t_mutex *mutex, long *var, long value)
{
	mutex_action(mutex, LOCK);
	*var = value;
	mutex_action(mutex, UNLOCK);
}

long	get_long(t_mutex *mutex, long *var)
{
	long	value;

	mutex_action(mutex, LOCK);
	value = *var;
	mutex_action(mutex, UNLOCK);
	return (value);
}

bool	dinner_finished(t_table *table)
{
	return (get_bool(&table->rd_mutex, &table->finish));
}
