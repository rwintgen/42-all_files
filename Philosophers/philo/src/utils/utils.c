/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwintgen <rwintgen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 12:31:34 by rwintgen          #+#    #+#             */
/*   Updated: 2024/06/19 16:42:41 by rwintgen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// exits program and prints error message
void	err_exit(int err, char *msg)
{
	if (msg)
		write(STDERR_FILENO, msg, ph_strlen(msg));
	exit(err);
}

long	get_time(t_unit unit)
{
	struct timeval tv;

	if (gettimeofday(&tv, NULL))
		err_exit(E_GETTOD, MSG_GETTOD);
	if (unit == SECONDS)
		return (tv.tv_sec + tv.tv_usec / 1e6);
	if (unit == MILLISECONDS)
		return (tv.tv_sec * 1e3 + tv.tv_usec / 1e3);
	if (unit == MICROSECONDS)
		return (tv.tv_sec * 1e6 + tv.tv_usec);
	else
		err_exit(E_UNIT, MSG_UNIT);
	return (ERROR);
}
