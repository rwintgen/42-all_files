/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_handling.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deymons <deymons@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 06:15:08 by amalangi          #+#    #+#             */
/*   Updated: 2024/04/19 15:44:43 by deymons          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int exec_builtin(t_cmd *cmd, t_envp *envp)
{
	int exit_code;

	exit_code = 0;
	if (!ft_strncmp(cmd->cmd_and_args[0], "echo", 4))
		exit_code = ft_echo(cmd, envp);
	else if (!ft_strncmp(cmd->cmd_and_args[0], "cd", 2))
		exit_code = ft_cd(cmd, envp);
	exit(exit_code);
}