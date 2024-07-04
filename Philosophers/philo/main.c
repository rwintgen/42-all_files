/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwintgen <rwintgen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 12:02:31 by rwintgen          #+#    #+#             */
/*   Updated: 2024/07/01 15:31:15 by rwintgen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_table	table;

	if (argc != 5 && argc != 6)
		return (err_msg(E_ARGC, MSG_USAGE));
	if (parse_input(argc, argv, &table) == ERROR)
		return (err_msg(E_ARGV, MSG_NUM));
	if (init_data(&table) == ERROR)
		return (err_msg(E_MALLOC, MSG_MALLOC));
	start_dinner(&table);
	clean(&table);
	return (EXIT_SUCCESS);
}
