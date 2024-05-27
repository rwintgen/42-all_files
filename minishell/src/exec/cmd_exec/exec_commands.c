/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_commands.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwintgen <rwintgen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 14:18:05 by deymons           #+#    #+#             */
/*   Updated: 2024/05/27 17:31:24 by rwintgen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	ft_exec(t_sh *sh);
static void	exec_current_cmd(char *path_to_cmd, t_sh *sh, char **envp_c);
static bool	exec_solo_builtin(t_sh *sh, t_cmd *cmd, int *exit_code);
static void	exec_heredoc(t_cmd *cmd, t_sh *sh);

// loops until all commands are executed
void	exec_commands(t_sh *sh)
{
	t_cmd		*tmp;
	int			status;
	int			last_pid;

	tmp = sh->cmd;
	while (sh->cmd)
	{
		last_pid = ft_exec(sh);
		if (sh->cmd->is_builtin && count_commands(sh->cmd) == 1)
		{
			sh->exit_code = last_pid;
			return ;
		}
		if (sh->cmd->input_fd != sh->saved_stdfd[0])
			close_if_valid(sh->cmd->input_fd);
		if (sh->cmd->output_fd != sh->saved_stdfd[1])
			close_if_valid(sh->cmd->output_fd);
		sh->cmd = sh->cmd->next;
	}
	sh->cmd = tmp;
	waitpid(last_pid, &status, 0);
	if (!(last_cmd_is_heredoc(sh->arg) && sh->exit_code == 130))
		sh->exit_code = exit_code_handler(errno, status);
}

// executes single command
static int	ft_exec(t_sh *sh)
{
	pid_t	pid;
	int		exit_code;
	char	*path_to_cmd;
	char	**envp_c;

	if (exec_solo_builtin(sh, sh->cmd, &exit_code))
		return (exit_code);
	pid = ft_fork(sh);
	if (pid != 0)
		return (pid);
	check_valid_fds(sh);
	exec_heredoc(sh->cmd, sh);
	redirect_io(sh->cmd);
	if (sh->cmd->is_builtin)
		exit(exec_and_exit(sh->cmd, &sh->envp, sh, exit_code));
	path_to_cmd = get_path(sh->cmd, sh->envp);
	envp_c = restore_envp(sh->envp);
	if (!envp_c)
		err_exit_envp(sh, path_to_cmd);
	exec_current_cmd(path_to_cmd, sh, envp_c);
	return (ERROR);
}

// executes current classic command
static void	exec_current_cmd(char *path_to_cmd, t_sh *sh, char **envp_c)
{
	if (!path_to_cmd
		|| execve(path_to_cmd, sh->cmd->cmd_and_args, envp_c) == ERROR)
	{
		cmd_err_msg(sh->cmd->cmd_and_args[0]);
		ft_free_char_tab(envp_c);
		close_all_fds();
		if (!sh->cmd->cmd_and_args[0][0])
		{
			if (path_to_cmd)
				free(path_to_cmd);
			free_sh(sh);
			exit(127);
		}
		exit(free_sh(sh));
	}
}

// executes single builtin command
static bool	exec_solo_builtin(t_sh *sh, t_cmd *cmd, int *exit_code)
{
	if (cmd->is_builtin && count_commands(cmd) == 1)
	{
		if (!redirect_io_nofork(sh, cmd))
		{
			*exit_code = 1;
			return (true);
		}
		*exit_code = exec_builtin(cmd, &sh->envp, sh);
		restore_io_nofork(sh, cmd);
		return (true);
	}
	return (false);
}

// executes heredoc command
static void	exec_heredoc(t_cmd *cmd, t_sh *sh)
{
	if (!ft_strcmp(cmd->cmd_and_args[0], EMPTY_HEREDOC))
	{
		redirect_io(cmd);
		free_sh(sh);
		close_all_fds();
		exit(EXIT_SUCCESS);
	}
}
