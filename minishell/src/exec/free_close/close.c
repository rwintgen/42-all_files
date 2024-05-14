/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwintgen <rwintgen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 12:18:33 by rwintgen          #+#    #+#             */
/*   Updated: 2024/05/14 13:34:14 by rwintgen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// clsoes all FDs but standard ones
void	close_all_fds(void)
{
	int	saved_errno;
	int	i;

	saved_errno = errno;
	i = 3;
	while (i < 1024)
	{
		close(i);
		i++;
	}
	errno = saved_errno;
}

// closes a FD if it is valid
void	close_if_valid(int fd)
{
	if (fd > 0)
		close(fd);
}

//closes duped standard FDs
void	close_saved_fds(int saved_stdfd[2])
{
	close(saved_stdfd[0]);
	close(saved_stdfd[1]);
}
