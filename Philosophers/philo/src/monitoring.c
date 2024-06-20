/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwintgen <rwintgen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 16:09:17 by rwintgen          #+#    #+#             */
/*   Updated: 2024/06/20 16:35:51 by rwintgen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*monitor(void *param)
{
	t_table	*table;

	table = (t_table*)param;
	while (!all_threads_running(&table->table_mutex,
			table->running_threads_count, table->philo_count))
		;
	while (!dinner_finished(table))
	{
		; // TODO
	}
}