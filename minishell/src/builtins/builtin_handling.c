/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_handling.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwintgen <rwintgen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 06:15:08 by amalangi          #+#    #+#             */
/*   Updated: 2024/04/20 14:39:14 by rwintgen         ###   ########.fr       */
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
	else if (!ft_strncmp(cmd->cmd_and_args[0], "pwd", 3))
		exit_code = ft_pwd();
	// else if (!ft_strncmp(cmd->cmd_and_args[0], "export", 6))
	// 	exit_code = ft_export(cmd, envp);
	// else if (!ft_strncmp(cmd->cmd_and_args[0], "unset", 5))
	// 	exit_code = ft_unset(cmd, envp);
	// else if (!ft_strncmp(cmd->cmd_and_args[0], "env", 3))
	// 	exit_code = ft_env(envp);
	// else if (!ft_strncmp(cmd->cmd_and_args[0], "exit", 4))
	// 	exit_code = ft_exit(cmd);
	exit(exit_code);
}