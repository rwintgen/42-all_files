/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwintgen <rwintgen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 16:58:03 by rwintgen          #+#    #+#             */
/*   Updated: 2024/06/27 13:51:07 by rwintgen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

static bool	valid_arg(char *arg);
static bool	valid_nb(char *nb);

// parses argv and stores it in table
void	parse_input(int argc, char **argv, t_table *table)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (!valid_arg(argv[i]))
			err_exit(E_ARGV, MSG_NUM);
		i++;
	}
	table->philo_count = ph_atol(argv[1]);
	table->time_to_die = ph_atol(argv[2]) * 1e3;
	table->time_to_eat = ph_atol(argv[3]) * 1e3;
	table->time_to_sleep = ph_atol(argv[4]) * 1e3;
	table->meals_needed = NO_MEALS;
	if (argv[5])
		table->meals_needed = ph_atol(argv[5]);
	init_semaphores(table);
}

// checks if a char is a digit
bool	is_num(char c)
{
	return (c >= '0' && c <= '9');
}

// checks if a char is a whitespace
bool	is_whitespace(char c)
{
	return (c == ' '
		|| c == '\t'
		|| c == '\n'
		|| c == '\v'
		|| c == '\f'
		|| c == '\r');
}

// checks that argv[i] is valid
static bool	valid_arg(char *arg)
{
	int	i;
	int	start;

	i = 0;
	if (!arg)
		return (false);
	while (arg[i] && is_whitespace(arg[i]))
		i++;
	if (arg[i] == '+')
		i++;
	start = i;
	if (!is_num(arg[i]))
		return (false);
	if (!valid_nb(&arg[start]))
		return (false);
	return (true);
}

// checks that a full-digit argv is valid
static bool	valid_nb(char *nb)
{
	int	len;
	int	n;

	len = ph_nblen(nb);
	if (len == 0)
		return (false);
	if (len > 10)
		return (false);
	n = ph_atol(nb);
	if (n == ERROR || n == 0)
		return (false);
	return (true);
}
