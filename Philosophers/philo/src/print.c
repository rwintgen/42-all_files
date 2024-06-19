/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwintgen <rwintgen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 16:51:24 by rwintgen          #+#    #+#             */
/*   Updated: 2024/06/19 17:10:34 by rwintgen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_status(t_philo *philo, t_state state)
{
	long	elapsed;

	elapsed = get_time(MILLISECONDS) - philo->table->start_time;
	if (philo->full)
		return ;
	mutex_action(&philo->table->print_mutex, LOCK);
	if (!dinner_finished(philo->table))
	{
		if (state == TAKE_FORK && !dinner_finished(philo->table))
			printf("%ld %d has taken a fork\n", elapsed, philo->id);
		else if (state == EATING)
			printf("%ld %d is eating\n", elapsed, philo->id);
		else if (state == SLEEPING)
			printf("%ld %d is sleeping\n", elapsed, philo->id);
		else if (state == THINKING)
			printf("%ld %d is thinking\n", elapsed, philo->id);
		else if (state == DEAD)
			printf("%ld %d died\n", elapsed, philo->id);
	}
	mutex_action(&philo->table->print_mutex, UNLOCK);

}