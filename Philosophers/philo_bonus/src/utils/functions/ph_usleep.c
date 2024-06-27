/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_usleep.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwintgen <rwintgen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 15:52:19 by rwintgen          #+#    #+#             */
/*   Updated: 2024/06/27 15:59:07 by rwintgen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	ph_usleep(long time)
{
	long	start;

	start = get_time(MICROSECONDS);
	while (get_time(MICROSECONDS) - start < time)
		usleep(50);
}
