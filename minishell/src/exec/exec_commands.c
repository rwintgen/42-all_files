/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_commands.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwintgen <rwintgen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 14:18:05 by deymons           #+#    #+#             */
/*   Updated: 2024/04/20 11:56:18 by rwintgen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int exit_code_handler(int error_code, int status)
{
    if (WIFEXITED(status))
        return (WEXITSTATUS(status));
    else if (WIFSIGNALED(status))
        return (128 + WTERMSIG(status));
    else if (WIFSTOPPED(status))
        return (128 + WSTOPSIG(status));
    else if (WIFCONTINUED(status))
        return (0);
    else if (error_code == ENOENT)
        return (127);
    else if (error_code == EACCES)
        return (126);
    else
        return (1);
}

int set_exit_code(int error_code)
{
	if (error_code == ENOENT)
		return (127);
	else if (error_code == EACCES)
		return (126);
	else
		return (1);
}

int	ft_exec(t_sh *sh)
{
	pid_t	pid;
	int		exit_code;
	char	*path_to_cmd;
	char	**envp_c;

	pid = fork();
	if (pid == -1)
	{
		sh->cmd->skip_cmd = true;
		ft_putstr_fd("minishell: fork error\n", STDERR_FILENO);
		return (-1);
	}
	if (pid != 0)
		return (pid);
	printf("errno: %d\n\n", errno);
	if (sh->cmd->input_fd < 0)
		exit(free_sh(sh));
	else if (sh->cmd->output_fd < 0)
		exit(free_sh(sh));
	if (!ft_strncmp(sh->cmd->cmd_and_args[0], "chibron", 7))
	{
		redirect_io(sh->cmd);
		exit(0);
	}
	redirect_io(sh->cmd);
	if (sh->cmd->is_builtin)
	{
		exit_code = exec_builtin(sh->cmd, sh->envp);
		exit(free_sh(sh));
	}
	path_to_cmd = get_path(sh->cmd, sh->envp);
	envp_c = t_envp_to_envp(sh->envp);
	if (execve(path_to_cmd, sh->cmd->cmd_and_args, envp_c) == -1)
	{
		ft_putstr_fd("minishell: command not found: ", 2);
		ft_putendl_fd(sh->cmd->cmd_and_args[0], STDERR_FILENO);
		exit(free_sh(sh));
	}
	return (-1);
}

void	exec_commands(t_sh *sh)
{
	t_cmd 		*tmp;
	int			status;
	int			last_pid;

	while (sh->cmd)
	{
		tmp = sh->cmd;
		if (sh->cmd->skip_cmd == false) // TODO handle builtin exec here without forking
			last_pid = ft_exec(sh);
		if (sh->cmd->input_fd != sh->saved_stdfd[0] && sh->cmd->input_fd != STDIN_FILENO)
			close(sh->cmd->input_fd);
		if (sh->cmd->output_fd != sh->saved_stdfd[1] && sh->cmd->output_fd != STDOUT_FILENO)
			close(sh->cmd->output_fd);
		sh->cmd = tmp->next;

	}
	waitpid(last_pid, &status, 0);
	sh->exit_code = exit_code_handler(errno, status);
}

