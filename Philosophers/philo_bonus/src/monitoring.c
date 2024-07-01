/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwintgen <rwintgen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 14:52:49 by rwintgen          #+#    #+#             */
/*   Updated: 2024/07/01 12:41:06 by rwintgen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

static int	kill_all_processes(t_table *table);

// idles until monitor sets simulation as finished
void	*wait_death(void *param)
{
	t_table	*table;

	table = (t_table *)param;
	sem_wait(table->end_simulation);
	kill_all_processes(table);
	return (NULL);
}

// kills all philos' PIDs
static int	kill_all_processes(t_table *table)
{
	int	i;

	i = 0;
	while (i < table->philo_count)
		kill(table->philos[i++].pid, SIGTERM);
	return (EXIT_FAILURE);
}
