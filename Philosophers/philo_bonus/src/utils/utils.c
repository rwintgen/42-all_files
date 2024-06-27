/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwintgen <rwintgen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 13:39:27 by rwintgen          #+#    #+#             */
/*   Updated: 2024/06/27 15:58:55 by rwintgen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	free_all(t_table *table)
{
	free(table->philos);
	sem_close(table->sem_forks);
	sem_close(table->sem_print);
	sem_close(table->end_simulation);
}

// exits program and prints error message
void	err_exit(int err, char *msg)
{
	if (msg)
		write(STDERR_FILENO, msg, ph_strlen(msg));
	exit(err);
}

void	err_free_exit(t_table *table, int err, char *msg)
{
	if (msg)
		write(STDERR_FILENO, msg, ph_strlen(msg));
	if (table)
		free_all(table);
	exit(err);
}

// gets current time in specified unit
long	get_time(t_unit unit)
{
	struct timeval	tv;

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

// safely writes philos' status
void	print_status(t_philo *philo, t_state state)
{
	long	elapsed;

	elapsed = get_time(MILLISECONDS) - philo->table->start_time;
	sem_wait(philo->table->sem_print);
	if (state == TAKE_FORK)
		printf("%ld %d has taken a fork\n", elapsed, philo->id);
	else if (state == EATING)
		printf("%ld %d is eating\n", elapsed, philo->id);
	else if (state == SLEEPING)
		printf("%ld %d is sleeping\n", elapsed, philo->id);
	else if (state == THINKING)
		printf("%ld %d is thinking\n", elapsed, philo->id);
	sem_post(philo->table->sem_print);
}
