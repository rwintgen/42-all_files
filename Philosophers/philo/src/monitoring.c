/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwintgen <rwintgen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 16:09:17 by rwintgen          #+#    #+#             */
/*   Updated: 2024/06/24 13:19:52 by rwintgen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static bool	philo_died(t_philo *philo);

void	*monitor(void *param)
{
	t_table	*table;
	int		i;

	table = (t_table*)param;
	while (!all_threads_running(&table->table_mutex,
			table->running_threads_count, table->philo_count))
		;
	while (!dinner_finished(table))
	{
		i = 0;
		while (i < table->philo_count && !dinner_finished(table))
		{
			if (philo_died(&table->philos[i]))
			{
				set_bool(&table->table_mutex, &table->end_simulation, true);
				print_status(&table->philos[i], DEAD);
			}
			i++;
		}
	}
	return (NULL);
}

static bool	philo_died(t_philo *philo)
{
	long	elapsed;
	long	time_to_die;

	if (get_bool(&philo->mutex, &philo->full))
		return (false);
	elapsed = get_time(MILLISECONDS) - get_long(&philo->mutex, &philo->last_meal_time);
	time_to_die = philo->table->time_to_die / 1e3;
	if (elapsed > time_to_die)
		return (true);
	return (false);
}
