/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deymons <deymons@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 02:42:25 by amalangi          #+#    #+#             */
/*   Updated: 2024/04/19 14:56:46 by deymons          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

bool    need_new_line(char *str)
{
	int i;

	i = 0;
	if (!str)
		return (true);
	if (str[0] == '-')
		i++;
	while (str[i])
	{
		if (str[i] != 'n')
			return (true);
		i++;
	}
	return (false);
}

int ft_echo(t_cmd *cmd, t_envp *envp)
{
	(void)envp;

	int to_print;

	to_print = 1;
	if (!need_new_line(cmd->cmd_and_args[1]))
		to_print++;
	while (cmd->cmd_and_args[to_print])
	{
		ft_putstr_fd(cmd->cmd_and_args[to_print], STDOUT_FILENO);
		if (cmd->cmd_and_args[to_print + 1])
			ft_putstr_fd(" ", STDOUT_FILENO);
		to_print++;
	}
	if (need_new_line(cmd->cmd_and_args[1]))
		ft_putstr_fd("\n", STDOUT_FILENO);
	exit(0);
}