/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_table.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwintgen <rwintgen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 14:18:47 by rwintgen          #+#    #+#             */
/*   Updated: 2024/05/16 17:06:20 by rwintgen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	set_table(int argc, char **argv, t_table *table)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (!valid_arg(argv[i]))
			err_exit(E_ARGV, MSG_NUM);
		i++;
	}
	table->nb_philo = ph_atol(argv[1]);
	table->time_to_die = ph_atol(argv[2]) * 1e3;
	table->time_to_eat = ph_atol(argv[3]) * 1e3;
	table->time_to_sleep = ph_atol(argv[4]) * 1e3;
	table->nb_meals = NO_MEALS;
	if (argv[5])
		table->nb_meals = ph_atol(argv[5]);
}
