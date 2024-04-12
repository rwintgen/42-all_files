/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwintgen <rwintgen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 17:42:34 by rwintgen          #+#    #+#             */
/*   Updated: 2024/04/02 18:06:01 by rwintgen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	ft_exec(char *cmd, char **envp)
{
	char	*cmd_path;
	char	**s_cmd;

	if (!*cmd)
	{
		err_msg(ERR_CMD);
		exit(ERR_CMD);
	}
	s_cmd = ft_split(cmd, ' ');
	if (!s_cmd || !s_cmd[0])
	{
		err_msg(ERR_EXEC);
		ft_putendl_fd(s_cmd[0], 2);
		ft_free_char_tab(s_cmd);
		exit(ERR_EXEC);
	}
	cmd_path = ft_get_path(s_cmd[0], envp);
	if (execve(cmd_path, s_cmd, envp) == -1)
	{
		err_msg(ERR_EXEC);
		ft_putendl_fd(s_cmd[0], 2);
		ft_free_char_tab(s_cmd);
		exit(ERR_EXEC);
	}
}

void	exec_cmd_1(char *cmd, int *pipefd, int *filefd, char **envp)
{
	dup2(pipefd[1], 1);
	close(pipefd[0]);
	close(pipefd[1]);
	dup2(filefd[0], 0);
	close(filefd[0]);
	close(filefd[1]);
	ft_exec(cmd, envp);
}

void	exec_cmd_2(char *cmd, int *pipefd, int *filefd, char **envp)
{
	dup2(pipefd[0], 0);
	close(pipefd[1]);
	close(pipefd[0]);
	dup2(filefd[1], 1);
	close(filefd[1]);
	close(filefd[0]);
	ft_exec(cmd, envp);
}
