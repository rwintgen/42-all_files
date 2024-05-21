/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwintgen <rwintgen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 16:53:03 by rwintgen          #+#    #+#             */
/*   Updated: 2024/05/21 11:18:04 by rwintgen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_table	table;

	if (argc != 5 && argc != 6)
		err_exit(E_ARGC, MSG_USAGE);

	set_table(argc, argv, &table);
	debug_parsing(table);

	welcome_guests(&table);
	// eat_dinner(&table);
	// do_dishes(&table);
	return (EXIT_SUCCESS);
}
