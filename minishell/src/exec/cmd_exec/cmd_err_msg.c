/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_err_msg.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwintgen <rwintgen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 13:27:30 by rwintgen          #+#    #+#             */
/*   Updated: 2024/05/24 14:29:51 by rwintgen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static bool	ispath(char *cmd);

// writes approriate message to stderr
void	cmd_err_msg(char *cmd)
{
	if (ispath(cmd))
	{
		if (access(cmd, F_OK) != 0)
			print_err(E_FILE_EXIST, cmd, NULL, NULL);
		else if (access(cmd, X_OK) != 0)
			print_err(E_FILE_PERM, cmd, NULL, NULL);
		else
			print_err(E_FILE_DIR, cmd, NULL, NULL);
	}
	else
		print_err(E_CMD_NF, cmd, NULL, NULL);
}

// checks if the command is a path
static bool	ispath(char *cmd)
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
