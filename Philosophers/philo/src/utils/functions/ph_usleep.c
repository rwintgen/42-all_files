/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_usleep.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwintgen <rwintgen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 15:52:19 by rwintgen          #+#    #+#             */
/*   Updated: 2024/06/25 18:26:47 by rwintgen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ph_usleep(long time, t_table *table)
{
	long	start;

	start = get_time(MICROSECONDS);
	while (get_time(MICROSECONDS) - start < time)
	{
		if (dinner_finished(table))
			break ;
		while (get_time(MICROSECONDS) - start < time \
				&& !dinner_finished(table))
			;
	}
}
