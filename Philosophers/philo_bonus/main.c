/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwintgen <rwintgen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 16:22:19 by rwintgen          #+#    #+#             */
/*   Updated: 2024/07/01 12:09:30 by rwintgen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	main(int argc, char **argv)
{
	t_table	table;
	int		ret;

	ret = EXIT_SUCCESS;
	if (argc != 5 && argc != 6)
		err_exit(E_ARGC, MSG_USAGE);
	parse_input(argc, argv, &table);
	init_philos(&table);
	start_processes(&table);
	ret = wait_all_processes(&table);
	free_all(&table);
	return (ret);
}
