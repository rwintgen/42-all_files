/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwintgen <rwintgen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 12:18:33 by rwintgen          #+#    #+#             */
/*   Updated: 2024/04/24 12:17:27 by rwintgen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

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

void	close_if_valid(int fd)
{
	if (fd > 0)
		close(fd);
}

void	close_saved_fds(int saved_stdfd[2])
{
	close(saved_stdfd[0]);
	close(saved_stdfd[1]);
}
