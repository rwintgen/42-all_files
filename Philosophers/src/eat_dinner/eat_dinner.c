/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat_dinner.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwintgen <rwintgen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 14:20:05 by rwintgen          #+#    #+#             */
/*   Updated: 2024/05/23 15:42:17 by rwintgen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	eat_dinner(t_table *table)
{
	int	i;

	i = 0;
	if (table->nb_meals == 0)
		return ;
	if (table->nb_philo == 1)
		thread_action(&table->philos[0].thrd_id, eat_alone, &table->philos[0], CREATE);
	while (i < table->nb_philo && table->nb_philo > 1)
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
	set_bool(&table->rd_mutex, &table->finish, true);
	thread_action(&table->monitoring, NULL, NULL, JOIN);
}

void	*dine(void *param)
{
	t_philo	*philo;

	philo = (t_philo *)param;
	wait_all(philo->table);
	increment_long(&philo->table->rd_mutex, &philo->table->nb_threads);
	while (!dinner_finished(philo->table))
	{
		if (philo->full == true)
			break ;
		ph_eat(philo);
		ph_sleep(philo);
		ph_think(philo);
	}

	return (NULL);
}

void	*eat_alone(void *param)
{
	t_philo	*philo;

	philo = (t_philo *)param;
	wait_all(philo->table);
	increment_long(&philo->table->rd_mutex, &philo->table->nb_threads);
	print_status(philo, TAKE_FORK_ONE);
	while (!dinner_finished(philo->table))
		usleep(200);
	return (NULL);
}
