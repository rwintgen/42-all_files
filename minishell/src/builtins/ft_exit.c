/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwintgen <rwintgen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 15:14:32 by rwintgen          #+#    #+#             */
/*   Updated: 2024/04/29 15:44:17 by rwintgen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

bool	is_full_digit(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (false);
		i++;
	}
	return (true);
}

int	ft_exit(t_cmd *cmd)
{
	int		exit_code;

	exit_code = 0;
	if (!cmd->cmd_and_args[1])
		exit(exit_code);
	if (!is_full_digit(cmd->cmd_and_args[1]))
	{
		ft_putendl_fd(E_EXIT_NUM, STDERR_FILENO);
		// free sh
		exit(2);
	}
	if (cmd->cmd_and_args[2])
	{
		ft_putendl_fd(E_EXIT_ARGC, STDERR_FILENO);
		return (1);
	}
	else 
		exit_code = ft_atoi(cmd->cmd_and_args[1]);
	exit(exit_code);
}
