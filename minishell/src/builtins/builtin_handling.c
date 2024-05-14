/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_handling.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwintgen <rwintgen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 06:15:08 by amalangi          #+#    #+#             */
/*   Updated: 2024/05/14 12:49:38 by rwintgen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	exec_builtin(t_cmd *cmd, t_envp **envp, t_sh *sh)
{
	int	exit_code;

	exit_code = 0;
	if (!ft_strcmp(cmd->cmd_and_args[0], "echo"))
		exit_code = ft_echo(cmd, *envp);
	else if (!ft_strcmp(cmd->cmd_and_args[0], "cd"))
		exit_code = ft_cd(cmd, *envp);
	else if (!ft_strcmp(cmd->cmd_and_args[0], "pwd"))
		exit_code = ft_pwd();
	else if (!ft_strcmp(cmd->cmd_and_args[0], "export"))
		exit_code = ft_export(cmd, envp);
	else if (!ft_strcmp(cmd->cmd_and_args[0], "unset"))
		exit_code = ft_unset(cmd, envp);
	else if (!ft_strcmp(cmd->cmd_and_args[0], "env"))
		exit_code = ft_env(cmd->cmd_and_args[1], *envp);
	else if (!ft_strcmp(cmd->cmd_and_args[0], "exit"))
		exit_code = ft_exit(cmd, sh);
	return (exit_code);
}

bool	is_builtin(char *cmd)
{
	if (!ft_strcmp(cmd, "echo")
		|| !ft_strcmp(cmd, "cd")
		|| !ft_strcmp(cmd, "pwd")
		|| !ft_strcmp(cmd, "export")
		|| !ft_strcmp(cmd, "unset")
		|| !ft_strcmp(cmd, "env")
		|| !ft_strcmp(cmd, "exit"))
		return (true);
	return (false);
}
