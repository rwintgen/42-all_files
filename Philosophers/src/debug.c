/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwintgen <rwintgen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 11:00:57 by rwintgen          #+#    #+#             */
/*   Updated: 2024/05/22 13:30:31 by rwintgen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	debug_parsing(t_table table)
{
	printf("\n///// PARSING /////\n\n");
	printf("nb philo:\t%ld\n", table.nb_philo);
	printf("time to die:\t%ld us\n", table.time_to_die);
	printf("time to eat:\t%ld us\n", table.time_to_eat);
	printf("time to sleep:\t%ld us\n", table.time_to_sleep);
	if (table.nb_meals == NO_MEALS)
		printf("meals needed:\tNONE\n\n");
	else
		printf("meals needed:\t%ld\n\n", table.nb_meals);
}

void	debug_init(t_table table)
{
	t_philo	*philo;
	t_fork	*forks;
	int		i;

	philo = table.philos;
	forks = table.forks;

	i = 0;
	printf("////// INIT //////\n\n");
	printf("nb philo:\t%ld\n\n", table.nb_philo);
	while (philo && i < table.nb_philo)
	{
		printf("philo id:\t%d\n", philo[i].id);
		i++;
	}
	printf("\n");
	i = 0;
	while (forks && i < table.nb_philo)
	{
		printf("fork id:\t%d\n", forks[i].id);
		i++;
	}
}
