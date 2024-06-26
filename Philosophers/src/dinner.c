/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dinner.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwintgen <rwintgen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 13:26:35 by rwintgen          #+#    #+#             */
/*   Updated: 2024/06/24 17:38:54 by rwintgen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	join_threads(t_table *table);

// creates threads and launches simulation
void	start_dinner(t_table *table)
{
	int	i;

	i = 0;
	if (table->meals_needed == 0)
		return ;
	else if (table->philo_count == 1)
		thread_action(&table->philos[0].thread_id, \
					alone_dinner_routine, &table->philos[0], CREATE);
	else
	{
		while (i < table->philo_count)
		{
			thread_action(&table->philos[i].thread_id, \
						dinner_routine, &table->philos[i], CREATE);
			i++;
		}
	}
	thread_action(&table->monitor, monitor, table, CREATE);
	table->start_time = get_time(MILLISECONDS);
	set_bool(&table->table_mutex, &table->all_threads_ready, true);
	join_threads(table);
}

// handles thinking of each philo thread
void	think(t_philo *philo, bool pre_simulation)
{
	long	t_eat;
	long	t_sleep;
	long	t_think;

	if (pre_simulation)
		print_status(philo, THINKING);
	if (philo->table->philo_count % 2 == 0)
		return ;
	t_eat = philo->table->time_to_eat;
	t_sleep = philo->table->time_to_sleep;
	t_think = t_eat * 2 - t_sleep;
	if (t_think < 0)
		t_think = 0;
	ph_usleep(t_think * 0.42, philo->table);
}

// handles the eating of each philo thread
void	eat(t_philo *philo)
{
	mutex_action(&philo->fork_one->mutex, LOCK);
	print_status(philo, TAKE_FORK);
	mutex_action(&philo->fork_two->mutex, LOCK);
	print_status(philo, TAKE_FORK);
	set_long(&philo->mutex, &philo->last_meal_time, get_time(MILLISECONDS));
	philo->meals_count++;
	print_status(philo, EATING);
	ph_usleep(philo->table->time_to_eat, philo->table);
	if (philo->table->meals_needed \
		&& philo->meals_count == philo->table->meals_needed)
		set_bool(&philo->mutex, &philo->full, true);
	mutex_action(&philo->fork_one->mutex, UNLOCK);
	mutex_action(&philo->fork_two->mutex, UNLOCK);
}

// joins philos & monitor threads
static void	join_threads(t_table *table)
{
	int	i;

	i = 0;
	while (i < table->philo_count)
	{
		thread_action(&table->philos[i].thread_id, NULL, NULL, JOIN);
		i++;
	}
	set_bool(&table->table_mutex, &table->end_simulation, true);
	thread_action(&table->monitor, NULL, NULL, JOIN);
}
