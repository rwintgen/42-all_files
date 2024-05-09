/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_handling.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwintgen <rwintgen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 06:15:08 by amalangi          #+#    #+#             */
/*   Updated: 2024/05/09 16:07:47 by rwintgen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	exec_builtin(t_cmd *cmd, t_envp **envp, t_sh *sh)
{
	int	exit_code;

	exit_code = 0;
	if (!ft_strncmp(cmd->cmd_and_args[0], "echo", 4))
		exit_code = ft_echo(cmd, *envp);
	else if (!ft_strncmp(cmd->cmd_and_args[0], "cd", 2))
		exit_code = ft_cd(cmd, *envp);
	else if (!ft_strncmp(cmd->cmd_and_args[0], "pwd", 3))
		exit_code = ft_pwd();
	else if (!ft_strncmp(cmd->cmd_and_args[0], "export", 6))
		exit_code = ft_export(cmd, envp);
	else if (!ft_strncmp(cmd->cmd_and_args[0], "unset", 5))
		exit_code = ft_unset(cmd, envp);
	else if (!ft_strncmp(cmd->cmd_and_args[0], "env", 3))
		exit_code = ft_env(cmd->cmd_and_args[1], *envp);
	else if (!ft_strncmp(cmd->cmd_and_args[0], "exit", 4))
		exit_code = ft_exit(cmd, sh);
	return (exit_code);
}

// checks if cmd is a builtin
bool	is_builtin(char *cmd)
{
	if (!ft_strncmp(cmd, "echo", 5)
		|| !ft_strncmp(cmd, "cd", 3)
		|| !ft_strncmp(cmd, "pwd", 4)
		|| !ft_strncmp(cmd, "export", 7)
		|| !ft_strncmp(cmd, "unset", 6)
		|| !ft_strncmp(cmd, "env", 4)
		|| !ft_strncmp(cmd, "exit", 5))
		return (true);
	return (false);
}
