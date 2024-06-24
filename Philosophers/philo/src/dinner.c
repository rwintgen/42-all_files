/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dinner.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwintgen <rwintgen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 13:26:35 by rwintgen          #+#    #+#             */
/*   Updated: 2024/06/24 13:21:28 by rwintgen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	eat(t_philo *philo);
static void	think(t_philo *philo);

// creates threads and launches simulation
void	start_dinner(t_table *table)
{
	int	i;

	i = 0;
	if (table->meals_needed == 0)
		return ;
	else if (table->philo_count == 1)
		return ; // TODO eat alone
	else
	{
		while (i < table->philo_count)
		{
			thread_action(&table->philos[i].thread_id, dinner_routine, &table->philos[i], CREATE);
			i++;
		}
	}
	thread_action(&table->monitor, monitor, table, CREATE);
	table->start_time = get_time(MILLISECONDS);
	set_bool(&table->table_mutex, &table->all_threads_ready, true);
	i = 0;
	while (i < table->philo_count)
	{
		thread_action(&table->philos[i].thread_id, NULL, NULL, JOIN);
		i++;
	}
}

// routine to be executed by each thread
void	*dinner_routine(void *data)
{
	t_philo	*philo;

	philo = (t_philo *)data;
	wait_all_threads(philo->table);
	set_long(&philo->mutex, &philo->last_meal_time, get_time(MILLISECONDS));
	increment_long(&philo->table->table_mutex, &philo->table->running_threads_count);
	while (!dinner_finished(philo->table))
	{
		if (philo->full)
			break ;
		eat(philo);
		print_status(philo, SLEEPING);
		ph_usleep(philo->table->time_to_sleep, philo->table);
		think(philo);
	}


	return (NULL);
}

static void	eat(t_philo *philo)
{
	mutex_action(&philo->fork_one->mutex, LOCK);
	print_status(philo, TAKE_FORK);
	mutex_action(&philo->fork_two->mutex, LOCK);
	print_status(philo, TAKE_FORK);

	set_long(&philo->mutex, &philo->last_meal_time, get_time(MILLISECONDS));
	philo->meals_count++;
	print_status(philo, EATING);
	ph_usleep(philo->table->time_to_eat, philo->table);
	if (philo->table->meals_needed && philo->meals_count == philo->table->meals_needed)
		set_bool(&philo->mutex, &philo->full, true);

	mutex_action(&philo->fork_one->mutex, UNLOCK);
	mutex_action(&philo->fork_two->mutex, UNLOCK);
}

static void	think(t_philo *philo)
{
	print_status(philo, THINKING);
}
