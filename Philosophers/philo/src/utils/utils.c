/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwintgen <rwintgen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 12:31:34 by rwintgen          #+#    #+#             */
/*   Updated: 2024/06/27 15:28:27 by rwintgen         ###   ########.fr       */
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

// frees allocated resources and destroys mutexes
void	clean(t_table *table)
{
	t_philo	*current;
	int		i;

	i = 0;
	while (i < table->philo_count)
	{
		current = &table->philos[i];
		mutex_action(&current->mutex, DESTROY);
		i++;
	}
	mutex_action(&table->table_mutex, DESTROY);
	mutex_action(&table->print_mutex, DESTROY);
	free(table->forks);
	free(table->philos);
}

// safely writes philos' status
void	print_status(t_philo *philo, t_state state)
{
	long	elapsed;

	elapsed = get_time(MILLISECONDS) - philo->table->start_time;
	if (philo->full)
		return ;
	mutex_action(&philo->table->print_mutex, LOCK);
	if (!dinner_finished(philo->table))
	{
		if (state == TAKE_FORK)
			printf("%ld %d has taken a fork\n", elapsed, philo->id);
		else if (state == EATING)
			printf("%ld %d is eating\n", elapsed, philo->id);
		else if (state == SLEEPING)
			printf("%ld %d is sleeping\n", elapsed, philo->id);
		else if (state == THINKING)
			printf("%ld %d is thinking\n", elapsed, philo->id);
	}
	if (state == DEAD)
		printf("%ld %d died\n", elapsed, philo->id);
	mutex_action(&philo->table->print_mutex, UNLOCK);
}
