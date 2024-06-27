/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwintgen <rwintgen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 14:43:09 by rwintgen          #+#    #+#             */
/*   Updated: 2024/06/27 16:08:22 by rwintgen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

static int	dinner_routine(t_philo *philo);
static void	eating(t_philo *philo, t_table *table);
static void	sleeping(t_philo *philo, t_table *table);

int	start_processes(t_table *table)
{
	int	i;

	table->start_time = get_time(MILLISECONDS);
	i = 0;
	while (i < table->philo_count)
	{
		table->philos[i].pid = fork();
		if (table->philos[i].pid == 0) // if child
			return (dinner_routine(&table->philos[i]));
		i++;
	}
	if (pthread_create(&table->death_monitor, NULL, wait_death, table->philos))
		err_free_exit(table, E_THRD, MSG_THRD);
	return (ERROR);
}

// waits for all processes to finish


// routine to be executed by each child
static int	dinner_routine(t_philo *philo)
{
	pthread_t	self_death_checker;
	t_table 	*table;

	pthread_create(&self_death_checker, NULL, wait_death, philo);
	table = philo->table;
	if (philo->id % 2)
		ph_usleep(philo->table->time_to_eat);
	while (true)
	{
		if (philo->meals_count >= table->meals_needed)
			break ;
		eating(philo, table);
		sleeping(philo, table);
		ph_usleep((table->time_to_die - table->time_to_eat - table->time_to_sleep) / 2);
	}
	sem_post(table->end_simulation);
	return (ERROR);
}

static void	eating(t_philo *philo, t_table *table)
{
	sem_wait(table->sem_forks);
	print_status(philo, TAKE_FORK);
	sem_wait(table->sem_forks);
	print_status(philo, TAKE_FORK);
	print_status(philo, EATING);
	ph_usleep(table->time_to_eat);
	philo->meals_count++;
	sem_wait(philo->sem_last_meal);
	philo->last_meal = get_time(MILLISECONDS) - table->start_time;
	sem_post(philo->sem_last_meal);
}

static void	sleeping(t_philo *philo, t_table *table)
{
	sem_post(table->sem_forks);
	print_status(philo, SLEEPING);
	ph_usleep(table->time_to_sleep);
}
