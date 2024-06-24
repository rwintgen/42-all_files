/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routines.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwintgen <rwintgen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 17:35:12 by rwintgen          #+#    #+#             */
/*   Updated: 2024/06/24 17:36:08 by rwintgen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// routine to be executed by each thread
void	*dinner_routine(void *data)
{
	t_philo	*philo;

	philo = (t_philo *)data;
	wait_all_threads(philo->table);
	set_long(&philo->mutex, &philo->last_meal_time, get_time(MILLISECONDS));
	increment_long(&philo->table->table_mutex, \
				&philo->table->running_threads_count);
	offset_philos(philo);
	while (!dinner_finished(philo->table))
	{
		if (philo->full)
			break ;
		eat(philo);
		print_status(philo, SLEEPING);
		ph_usleep(philo->table->time_to_sleep, philo->table);
		think(philo, false);
	}
	return (NULL);
}

// routine for a single philosopher
void	*alone_dinner_routine(void *data)
{
	t_philo	*philo;

	philo = (t_philo *)data;
	wait_all_threads(philo->table);
	set_long(&philo->mutex, &philo->last_meal_time, get_time(MILLISECONDS));
	increment_long(&philo->table->table_mutex, \
				&philo->table->running_threads_count);
	print_status(philo, TAKE_FORK);
	while (!dinner_finished(philo->table))
		usleep(200);
	return (NULL);
}
