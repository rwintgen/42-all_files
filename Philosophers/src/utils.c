/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwintgen <rwintgen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 16:53:03 by rwintgen          #+#    #+#             */
/*   Updated: 2024/05/21 12:27:41 by rwintgen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	err_exit(int err, char *msg)
{
	if (msg)
		write(STDERR_FILENO, msg, ph_strlen(msg));
	exit(err);
}
