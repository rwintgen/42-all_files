/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_usleep.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwintgen <rwintgen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 15:52:19 by rwintgen          #+#    #+#             */
/*   Updated: 2024/05/22 16:05:49 by rwintgen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ph_usleep(t_time time, t_table *table)
{
	t_time	start;
	t_time	remaining;
	t_time	elapsed;

	start = get_time(MICROSECONDS);
	while (get_time(MICROSECONDS) - start < time)
	{
		if (dinner_finished(table))
			break ;
		elapsed = get_time(MICROSECONDS) - start;
		remaining = time - elapsed;
		if (remaining > 1e3)
			usleep(remaining / 2);
		while (get_time(MICROSECONDS) - start < time)
			;
	}
}
