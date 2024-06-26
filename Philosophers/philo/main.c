/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwintgen <rwintgen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 12:02:31 by rwintgen          #+#    #+#             */
/*   Updated: 2024/06/26 17:04:52 by rwintgen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_table	table;

	if (argc != 5 && argc != 6)
		err_exit(E_ARGC, MSG_USAGE);
	parse_input(argc, argv, &table);
	init_data(&table);
	// start_dinner(&table);
	// clean(&table);
	return (EXIT_SUCCESS);
}
