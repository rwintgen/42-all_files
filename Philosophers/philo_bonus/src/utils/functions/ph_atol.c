/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwintgen <rwintgen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 14:26:13 by rwintgen          #+#    #+#             */
/*   Updated: 2024/06/27 13:42:21 by rwintgen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

long	ph_atol(char *str)
{
	long	nb;
	int		i;

	nb = 0;
	i = 0;
	while (is_whitespace(str[i]) || str[i] == '+')
		i++;
	while (is_num(str[i]))
	{
		nb = nb * 10 + str[i] - '0';
		i++;
	}
	if (i > 10 || nb > INT_MAX)
		return (ERROR);
	return (nb);
}
