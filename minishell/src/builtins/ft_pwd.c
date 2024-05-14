/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwintgen <rwintgen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 21:01:13 by deymons           #+#    #+#             */
/*   Updated: 2024/05/14 15:15:07 by rwintgen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_pwd(void)
{
	char	*buffer;

	buffer = getcwd(NULL, 0);
	if (buffer)
	{
		ft_putstr_fd(buffer, STDOUT_FILENO);
		ft_putstr_fd("\n", STDOUT_FILENO);
		free(buffer);
	}
	return (SUCCESS);
}
