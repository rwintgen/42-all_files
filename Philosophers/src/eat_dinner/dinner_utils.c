/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dinner_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwintgen <rwintgen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 15:10:34 by rwintgen          #+#    #+#             */
/*   Updated: 2024/05/23 15:10:54 by rwintgen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ph_eat(t_philo *philo)
{
	mutex_action(&philo->fork_one->mutex, LOCK);
	print_status(philo, TAKE_FORK_ONE);
	mutex_action(&philo->fork_two->mutex, LOCK);
	print_status(philo, TAKE_FORK_TWO);
	set_long(&philo->mutex, &philo->last_meal, get_time(MILLISECONDS));
	philo->nb_meals++;
	print_status(philo, EATING);
	if (philo->table->nb_meals > 0 && philo->nb_meals == philo->table->nb_meals)
		set_bool(&philo->mutex, &philo->full, true);
	mutex_action(&philo->fork_one->mutex, UNLOCK);
	mutex_action(&philo->fork_two->mutex, UNLOCK);
}

void	ph_sleep(t_philo *philo)
{
	print_status(philo, SLEEPING);
	ph_usleep(philo->table->time_to_sleep, philo->table);
}

void	ph_think(t_philo *philo)
{
	print_status(philo, THINKING);
}
