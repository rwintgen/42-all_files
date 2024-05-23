/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   welcome_guests.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwintgen <rwintgen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 14:20:10 by rwintgen          #+#    #+#             */
/*   Updated: 2024/05/22 16:12:26 by rwintgen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	sit_guests(t_table *table);
static void	give_forks(t_philo *philo, t_fork *forks, int index);

void	welcome_guests(t_table *table)
{
	int	i;

	i = 0;
	table->finish = false;
	table->threads_ready = false;
	table->philos = ph_malloc(sizeof(t_philo) * table->nb_philo);
	table->forks = ph_malloc(sizeof(t_fork) * table->nb_philo);
	mutex_action(&table->rd_mutex, INIT);
	mutex_action(&table->wr_mutex, INIT);
	while (i < table->nb_philo)
	{
		mutex_action(&table->forks[i].fork, INIT);
		table->forks[i].id = i;
		i++;
	}
	sit_guests(table);
}

static void	sit_guests(t_table *table)
{
	t_philo	*philo;
	int		i;

	philo = table->philos;
	i = 0;
	while (i < table->nb_philo)
	{
		philo = &table->philos[i];
		philo->id = i + 1;
		philo->nb_meals = 0;
		philo->full = false;
		philo->table = table;
		give_forks(philo, table->forks, i);
		i++;
	}
}

static void	give_forks(t_philo *philo, t_fork *forks, int index)
{
	int	philo_count;

	philo_count = philo->table->nb_philo;
	if (philo->id % 2 == 0)
	{
		philo->fork_one = &forks[(index + 1) % philo_count];
		philo->fork_two = &forks[index];
	}
	else
	{
		philo->fork_one = &forks[index];
		philo->fork_two = &forks[(index + 1) % philo_count];
	}
}
