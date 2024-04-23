/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_commands.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwintgen <rwintgen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 14:18:05 by deymons           #+#    #+#             */
/*   Updated: 2024/04/23 12:20:24 by rwintgen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

void	exec_commands(t_sh *sh)
{
	t_cmd		*tmp;
	int			status;
	int			last_pid;

	tmp = sh->cmd;
	while (sh->cmd)
	{
		if (sh->cmd->skip_cmd == false)
			last_pid = ft_exec(sh);
		if (sh->cmd->input_fd != sh->saved_stdfd[0]/*&& sh->cmd->input_fd != STDIN_FILENO*/)
			close_if_valid(sh->cmd->input_fd);
		if (sh->cmd->output_fd != sh->saved_stdfd[1]/*&& sh->cmd->output_fd != STDOUT_FILENO*/)
			close_if_valid(sh->cmd->output_fd);
		sh->cmd = sh->cmd->next;
	}
	sh->cmd = tmp;
	waitpid(last_pid, &status, 0);
	sh->exit_code = exit_code_handler(errno, status);
}

int	ft_exec(t_sh *sh)
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
	{
		exit_code = exec_builtin(sh->cmd, sh->envp);
		close_all_fds();
		exit(free_sh(sh));
	}
	path_to_cmd = get_path(sh->cmd, sh->envp);
	envp_c = restore_envp(sh->envp);
	exec_current_cmd(path_to_cmd, sh, envp_c);
	return (-1);
}

void	exec_current_cmd(char *path_to_cmd, t_sh *sh, char **envp_c)
{
	if (execve(path_to_cmd, sh->cmd->cmd_and_args, envp_c) == -1)
	{
		ft_putstr_fd("minishell: command not found: ", 2);
		ft_putendl_fd(sh->cmd->cmd_and_args[0], STDERR_FILENO);
		ft_free_char_tab(envp_c);
		close_all_fds();
		// free(path_to_cmd); // useless askip
		exit(free_sh(sh));
	}
}

bool	exec_solo_builtin(t_sh *sh, t_cmd *cmd, int *exit_code)
{
	if (cmd->is_builtin && count_commands(cmd) == 1)
	{
		redirect_io_nofork(sh, cmd);
		*exit_code = exec_builtin(cmd, sh->envp);
		restore_io_nofork(sh, cmd);
		return (true);
	}
	return (false);
}

void	exec_heredoc(t_cmd *cmd, t_sh *sh)
{
	if (!ft_strncmp(cmd->cmd_and_args[0], "chibron", 7))
	{
		redirect_io(cmd);
		free_sh(sh);
		close_all_fds();
		exit(0);
	}
}
