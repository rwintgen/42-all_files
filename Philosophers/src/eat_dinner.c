/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat_dinner.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwintgen <rwintgen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 14:20:05 by rwintgen          #+#    #+#             */
/*   Updated: 2024/05/22 16:10:39 by rwintgen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*dine(void *param)
{
	t_philo	*philo;

	philo = (t_philo *)param;
	wait_all(philo->table);
	while (!dinner_finished(philo->table))
	{
		// TODO
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
	table->start = get_time(MILLISECONDS);
	set_bool(&table->rd_mutex, &table->threads_ready, true);
	i = 0;
	while (i < table->nb_philo)
	{
		thread_action(&table->philos[i].thrd_id, NULL, NULL, JOIN);
		i++;
	}
}
