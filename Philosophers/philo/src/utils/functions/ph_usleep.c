/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_usleep.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwintgen <rwintgen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 15:52:19 by rwintgen          #+#    #+#             */
/*   Updated: 2024/06/19 16:50:15 by rwintgen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ph_usleep(long time, t_table *table)
{
	long	start;
	long	remaining;
	long	elapsed;

	start = get_time(MICROSECONDS);
	while (get_time(MICROSECONDS) - start < time)
	{
		if (dinner_finished(table))
			break ;
		elapsed = get_time(MICROSECONDS) - start;
		remaining = time - elapsed;
		if (remaining > 1e3)
			usleep(remaining / 2);
		else
		{
			while (get_time(MICROSECONDS) - start < time)
				;
		}
	}
}
