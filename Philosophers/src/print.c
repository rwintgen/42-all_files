/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwintgen <rwintgen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 16:13:31 by rwintgen          #+#    #+#             */
/*   Updated: 2024/05/23 12:47:50 by rwintgen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_status(t_philo *philo, t_state state)
{
	t_time	elapsed;

	if (philo->full)
		return ;
	elapsed = get_time(MILLISECONDS) - philo->table->start;
	mutex_action(&philo->table->wr_mutex, LOCK);
	if (!dinner_finished(philo->table))
	{
		if (state == TAKE_FORK_ONE || state == TAKE_FORK_TWO)
			printf(W "%-6ld" RST "%d has taken a fork\n", elapsed, philo->id);
		else if (state == EATING)
			printf(G "%-6ld" RST "%d is eating\n", elapsed, philo->id);
		else if (state == SLEEPING)
			printf(B "%-6ld" RST "%d is sleeping\n", elapsed, philo->id);
		else if (state == THINKING)
			printf(C "%-6ld" RST "%d is thinking\n", elapsed, philo->id);
		else if (state == DEAD)
			printf(R "%-6ld" RST "%d died\n", elapsed, philo->id);
	}
	mutex_action(&philo->table->wr_mutex, UNLOCK);
}
