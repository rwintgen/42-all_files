/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwintgen <rwintgen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 12:51:55 by rwintgen          #+#    #+#             */
/*   Updated: 2024/06/19 17:20:25 by rwintgen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	init_philos(t_table *table);
static void	give_forks(t_philo *philo, t_fork *forks, int index);

// inits table data before threading
void	init_data(t_table *table)
{
	int	i;

	table->end_simulation = false;
	table->philos = ph_malloc(sizeof(t_philo) * table->philo_count);
	mutex_action(&table->table_mutex, INIT);
	mutex_action(&table->print_mutex, INIT);
	table->forks = ph_malloc(sizeof(t_fork) * table->philo_count);
	i = 0;
	while (i < table->philo_count)
	{
		mutex_action(&table->forks[i].mutex, INIT);
		table->forks[i].id = i;
		i++;
	}
	init_philos(table);
}

// inits each philo's elements
static void	init_philos(t_table *table)
{
	t_philo	*philo;
	int		i;

	philo = table->philos;
	i = 0;
	while (i < table->philo_count)
	{
		philo = &table->philos[i];
		philo->id = i + 1;
		philo->full = false;
		philo->meals_count = 0;
		philo->table = table;
		mutex_action(&philo->mutex, INIT);
		give_forks(philo, table->forks, table->philo_count);
		i++;
	}
}

// inits all the forks on the table avoiding deadlocks
static void	give_forks(t_philo *philo, t_fork *forks, int index)
{
	int	philo_count;

	philo_count = philo->table->philo_count;
	if (philo->id % 2 == 0)
	{
		philo->fork_one = &forks[index];
		philo->fork_two = &forks[(index + 1) % philo_count];
	}
	else
	{
		philo->fork_one = &forks[(index + 1) % philo_count];
		philo->fork_two = &forks[index];
	}
}