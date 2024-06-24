/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sync.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwintgen <rwintgen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 13:48:06 by rwintgen          #+#    #+#             */
/*   Updated: 2024/06/24 17:00:07 by rwintgen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// waits until all threads are created
void	wait_all_threads(t_table *table)
{
	while (!get_bool(&table->table_mutex, &table->all_threads_ready))
		;
}

// waits until all threads start their routines
bool	all_threads_running(pthread_mutex_t *mutex, long *nb_threads, long nb_philos)
{
	bool	ret;

	ret = false;
	mutex_action(mutex, LOCK);
	if (*nb_threads == nb_philos)
		ret = true;
	mutex_action(mutex, UNLOCK);
	return (ret);
}

// offsets philo sync to force think 
void	offset_philos(t_philo *philo)
{
	if (philo->table->philo_count % 2 == 0)
	{
		if (philo->id % 2 == 0)
			ph_usleep(42e3, philo->table);
	}
	else
	{
		if (philo->id % 2)
			think(philo, true);
	}
}
