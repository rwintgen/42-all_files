/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwintgen <rwintgen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 13:49:51 by rwintgen          #+#    #+#             */
/*   Updated: 2024/07/01 12:43:25 by rwintgen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

static void	populate_philo_fields(t_philo *philo, t_table *table, int i);

// deletes previous semaphores, creates new ones and unlinks them
void	init_semaphores(t_table *table)
{
	sem_unlink("/sem_forks");
	sem_unlink("/sem_print");
	sem_unlink("/sem_finished");
	table->sem_forks = sem_open("/sem_forks", O_CREAT, 0644, \
								table->philo_count);
	table->sem_print = sem_open("/sem_print", O_CREAT, 0644, 1);
	table->end_simulation = sem_open("/sem_finished", O_CREAT, 0644, 1);
	sem_unlink("/sem_forks");
	sem_unlink("/sem_print");
	sem_unlink("/sem_finished");
	sem_wait(table->end_simulation);
}

// allocates memory for each instance of t_philo
void	init_philos(t_table *table)
{
	int		i;

	table->philos = malloc(sizeof(t_philo) * table->philo_count);
	if (!table->philos)
		err_exit(E_MALLOC, MSG_MALLOC);
	i = 0;
	while (i < table->philo_count)
	{
		populate_philo_fields(&table->philos[i], table, i);
		i++;
	}
}

// populates fields of each t_philo struct instance
static void	populate_philo_fields(t_philo *philo, t_table *table, int i)
{
	char	*id_str;
	char	*semaphore_name;

	philo = &table->philos[i];
	philo->id = i + 1;
	philo->full = false;
	philo->meals_count = 0;
	philo->last_meal = 0;
	philo->table = table;
	id_str = ph_itoa(philo->id);
	semaphore_name = ph_strjoin("/sem_last_meal", id_str);
	sem_unlink(semaphore_name);
	philo->sem_last_meal = sem_open(semaphore_name, O_CREAT, 0644, 1);
	sem_unlink(semaphore_name);
	free(id_str);
	free(semaphore_name);
}
