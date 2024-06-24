/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwintgen <rwintgen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 14:25:53 by rwintgen          #+#    #+#             */
/*   Updated: 2024/06/24 16:09:40 by rwintgen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// reads the value of a bool
bool	get_bool(pthread_mutex_t *mutex, bool *var)
{
	bool	value;

	mutex_action(mutex, LOCK);
	value = *var;
	mutex_action(mutex, UNLOCK);
	return (value);
}

// reads the value of a long
long	get_long(pthread_mutex_t *mutex, long *var)
{
	long	value;

	mutex_action(mutex, LOCK);
	value = *var;
	mutex_action(mutex, UNLOCK);
	return (value);
}

// checks if the simulation is over
inline bool	dinner_finished(t_table *table)
{
	return (get_bool(&table->table_mutex, &table->end_simulation) == true);
}
