/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sync.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwintgen <rwintgen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 15:05:41 by rwintgen          #+#    #+#             */
/*   Updated: 2024/05/23 13:41:15 by rwintgen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	wait_all(t_table *table)
{
	while (!get_bool(&table->rd_mutex, &table->threads_ready))
		;
}

bool	all_threads_running(t_mutex *mutex, long nb_threads, long nb_philos)
{
	bool	ret;

	ret = false;
	mutex_action(mutex, LOCK);
	if (nb_threads == nb_philos)
		ret = true;
	mutex_action(mutex, UNLOCK);
	return (ret);
}
