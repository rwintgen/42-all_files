/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwintgen <rwintgen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 11:00:57 by rwintgen          #+#    #+#             */
/*   Updated: 2024/05/21 12:26:03 by rwintgen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	debug_parsing(t_table table)
{
	printf("///// PARSING /////\n");
	printf("nb philo:\t%ld\n", table.nb_philo);
	printf("time to die:\t%ld us\n", table.time_to_die);
	printf("time to eat:\t%ld us\n", table.time_to_eat);
	printf("time to sleep:\t%ld us\n", table.time_to_sleep);
	printf("meals needed:\t%ld\n\n", table.nb_meals);
}
