/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwintgen <rwintgen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 02:42:25 by amalangi          #+#    #+#             */
/*   Updated: 2024/05/24 17:37:04 by rwintgen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static bool	need_new_line(char *str);

int	ft_echo(t_cmd *cmd, t_envp *envp)
{
	int	to_print;

	(void)envp;
	to_print = 1;
	while (!need_new_line(cmd->cmd_and_args[to_print]))
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
	return (SUCCESS);
}

static bool	need_new_line(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (true);
	if (str[0] == '-')
		i++;
	else
		return (true);
	if (!str[i])
		return (true);
	while (str[i])
	{
		if (str[i] != 'n')
			return (true);
		i++;
	}
	return (false);
}
