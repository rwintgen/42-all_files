/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwintgen <rwintgen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 14:56:05 by rwintgen          #+#    #+#             */
/*   Updated: 2024/05/16 16:39:31 by rwintgen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static bool	valid_nb(char *nb);

bool	valid_arg(char *arg)
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

bool	is_num(char c)
{
	if (!c || c < '0' || c > '9')
		return (false);
	return (true);
}

bool	is_whitespace(char c)
{
	return (c == ' '
		|| c == '\t'
		|| c == '\n'
		|| c == '\v'
		|| c == '\f'
		|| c == '\r');
}
