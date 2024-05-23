/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat_dinner.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwintgen <rwintgen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 14:20:05 by rwintgen          #+#    #+#             */
/*   Updated: 2024/05/23 14:10:14 by rwintgen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	ph_eat(t_philo *philo);
static void	ph_sleep(t_philo *philo);
static void	ph_think(t_philo *philo);

void	*dine(void *param)
{
	t_philo	*philo;

	philo = (t_philo *)param;
	wait_all(philo->table);
	increment_long(&philo->table->rd_mutex, &philo->table->nb_threads);
	while (!dinner_finished(philo->table))
	{
		if (philo->full == true)
		{
			printf("philo %d is full\n", philo->id);
			break ;
		}
		ph_eat(philo);
		ph_sleep(philo);
		ph_think(philo);
	}

	return (NULL);
}

void	eat_dinner(t_table *table)
{
	int	i;

	i = 0;
	if (table->nb_meals == 0)
		return ;
	else if (table->nb_philo == 1)
		return ;
		// TODO return eat_alone(table);
	while (i < table->nb_philo)
	{
		thread_action(&table->philos[i].thrd_id, dine, &table->philos[i], CREATE);
		i++;
	}
	thread_action(&table->monitoring, monitor, table, CREATE);
	table->start = get_time(MILLISECONDS);
	set_bool(&table->rd_mutex, &table->threads_ready, true);
	i = 0;
	while (i < table->nb_philo)
	{
		thread_action(&table->philos[i].thrd_id, NULL, NULL, JOIN);
		i++;
	}
}

static void	ph_eat(t_philo *philo)
{
	mutex_action(&philo->fork_one->mutex, LOCK);
	print_status(philo, TAKE_FORK_ONE);
	mutex_action(&philo->fork_two->mutex, LOCK);
	print_status(philo, TAKE_FORK_TWO);
	set_long(&philo->mutex, &philo->last_meal, get_time(MILLISECONDS));
	philo->nb_meals++;
	print_status(philo, EATING);
	if (philo->table->nb_meals > 0 && philo->nb_meals == philo->table->nb_meals)
		set_bool(&philo->mutex, &philo->full, true);
	mutex_action(&philo->fork_one->mutex, UNLOCK);
	mutex_action(&philo->fork_two->mutex, UNLOCK);
}

static void	ph_sleep(t_philo *philo)
{
	print_status(philo, SLEEPING);
	ph_usleep(philo->table->time_to_sleep, philo->table);
}

static void	ph_think(t_philo *philo)
{
	print_status(philo, THINKING);
}
