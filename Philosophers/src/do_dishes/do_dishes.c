/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_dishes.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwintgen <rwintgen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 14:20:15 by rwintgen          #+#    #+#             */
/*   Updated: 2024/05/23 16:19:48 by rwintgen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	do_dishes(t_table *table)
{
	int	i;

	i = 0;
	while (i < table->nb_philo)
	{
		mutex_action(&table->philos[i].mutex, DESTROY);
		i++;
	}
	mutex_action(&table->rd_mutex, DESTROY);
	mutex_action(&table->wr_mutex, DESTROY);
	free(table->forks);
	free(table->philos);
}
