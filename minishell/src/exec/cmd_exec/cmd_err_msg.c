/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_err_msg.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwintgen <rwintgen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 13:27:30 by rwintgen          #+#    #+#             */
/*   Updated: 2024/04/25 15:57:38 by rwintgen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	cmd_err_msg(char *cmd)
{
	if (ispath(cmd))
	{
		if (access(cmd, F_OK) != 0)
		{
			ft_putstr_fd(E_FILE_EXIST, STDERR_FILENO);
			ft_putendl_fd(cmd, STDERR_FILENO);
		}
		else if (access(cmd, X_OK) != 0)
		{
			ft_putstr_fd(E_FILE_PERM, STDERR_FILENO);
			ft_putendl_fd(cmd, STDERR_FILENO);
		}
		else
		{
			ft_putstr_fd(E_FILE_DIR, STDERR_FILENO);
			ft_putendl_fd(cmd, STDERR_FILENO);
		}
	}
	else
	{
		ft_putstr_fd(E_CMD_NF, 2);
		ft_putendl_fd(cmd, STDERR_FILENO);
	}
}

bool	ispath(char *cmd)
{
	int	i;

	i = 0;
	while (cmd[i])
	{
		if (cmd[i] == '/')
			return (true);
		i++;
	}
	return (false);
}
