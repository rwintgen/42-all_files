/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwintgen <rwintgen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 13:07:03 by rwintgen          #+#    #+#             */
/*   Updated: 2024/05/23 15:48:31 by rwintgen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static bool	philo_died(t_philo *philo);

void	*monitor(void *param)
{
	t_table	*table;
	int		i;

	table = (t_table *)param;
	// TODO data race in while below. check if necessary
	// while (!all_threads_running(&table->rd_mutex,
	// 		table->nb_threads, table->nb_philo))
	// 	usleep(1e3);
	while (!dinner_finished(table))
	{
		i = 0;
		while (i < table->nb_philo)
		{
			if (philo_died(&table->philos[i]))
			{
				printf("philo %d died\n", table->philos[i].id);
				set_bool(&table->wr_mutex, &table->finish, true);
				print_status(&table->philos[i], DEAD);
			}
			i++;
		}
	}
	return (NULL);
}

static bool	philo_died(t_philo *philo)
{
	t_time	elapsed;
	t_time	time_to_die;

	if (get_bool(&philo->mutex, &philo->full))
		return (false);
	elapsed = get_time(MILLISECONDS) - get_long(&philo->mutex, &philo->last_meal);
	time_to_die = philo->table->time_to_die / 1e3;
	if (elapsed > time_to_die)
		return (true);
	return (false);
}
