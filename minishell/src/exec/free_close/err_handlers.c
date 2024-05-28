/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err_handlers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwintgen <rwintgen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 17:01:49 by rwintgen          #+#    #+#             */
/*   Updated: 2024/05/28 15:18:34 by rwintgen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	*err_close_args(void)
{
	print_err(E_MALLOC, NULL, NULL, NULL);
	close_all_fds();
	return (NULL);
}

void	err_exit_envp(t_sh *sh, char *path_to_cmd)
{
	print_err(E_MALLOC, ": \"", sh->cmd->cmd_and_args[0], "\"");
	close_all_fds();
	free_sh(sh);
	free(path_to_cmd);
	exit(EXIT_FAILURE);
}

int	err_close_args_list(t_sh *sh, char *tofree)
{
	print_err(E_MALLOC, NULL, NULL, NULL);
	free_sh(sh);
	close_all_fds();
	if (tofree)
		free(tofree);
	return (ERROR);
}

int	exec_and_exit(t_cmd *cmd, t_envp **envp, t_sh *sh, int exit_code)
{
	exit_code = exec_builtin(cmd, envp, sh);
	close_all_fds();
	free_sh(sh);
	return (exit_code);
}

int	exit_handler(t_sh *sh)
{
	int	exit_code;

	exit_code = sh->exit_code;
	free_sh(sh);
	write(3, "exit\n", 5);
	close_all_fds();
	if (g_sig == SIGINT || g_sig == 130)
		exit_code = 130;
	return (exit_code);
}
