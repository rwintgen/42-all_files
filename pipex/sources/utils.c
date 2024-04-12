/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwintgen <rwintgen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 16:20:13 by rwintgen          #+#    #+#             */
/*   Updated: 2024/04/02 18:06:09 by rwintgen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

int	err_msg(int err_id)
{
	if (err_id == ERR_ARGC)
		ft_putstr_fd("pipex: need 4 arguments\n", 2);
	if (err_id == ERR_INFILE)
		ft_putstr_fd("pipex: can't access infile\n", 2);
	if (err_id == ERR_OUTFILE)
		ft_putstr_fd("pipex: can't access outfile\n", 2);
	if (err_id == ERR_PIPE)
		ft_putstr_fd("pipex: pipe failed\n", 2);
	if (err_id == ERR_EXEC)
		ft_putstr_fd("pipex: command not found: ", 2);
	if (err_id == ERR_CMD)
		ft_putstr_fd("pipex: need valid command\n", 2);
	return (err_id);
}

int	ft_open(char *file, int *fd, int flag)
{
	if (flag == FLAG_READ)
		*fd = open(file, O_RDONLY);
	else if (flag == FLAG_WRITE)
		*fd = open(file, O_TRUNC | O_CREAT | O_RDWR, 0644);
	return (*fd);
}

void	close_and_wait(int pipefd[2], int filefd[2], pid_t pid[2])
{
	close(pipefd[0]);
	close(pipefd[1]);
	waitpid(pid[0], NULL, 0);
	waitpid(pid[1], NULL, 0);
	close(filefd[0]);
	close(filefd[1]);
}

char	*ft_find_env_path(char **envp)
{
	int		i;
	int		j;
	char	*envp_name;

	if (!envp)
		return (NULL);
	i = 0;
	while (envp[i])
	{
		j = 0;
		while (envp[i][j] != '=' && envp[i][j])
			j++;
		envp_name = ft_substr(envp[i], 0, j);
		if (!(ft_strcmp(envp_name, "PATH")))
		{
			free(envp_name);
			return (envp[i] + j + 1);
		}
		free(envp_name);
		i++;
	}
	return (NULL);
}

char	*ft_get_path(char *cmd, char **envp)
{
	char	**sep_env_paths;
	char	*tmp;
	char	*cmd_full_path;
	int		i;

	sep_env_paths = ft_split(ft_find_env_path(envp), ':');
	i = 0;
	if (!sep_env_paths)
		return (cmd);
	while (sep_env_paths[i])
	{
		tmp = ft_strjoin(sep_env_paths[i], "/");
		cmd_full_path = ft_strjoin(tmp, cmd);
		free(tmp);
		if (access(cmd_full_path, F_OK | X_OK) == 0)
		{
			ft_free_char_tab(sep_env_paths);
			return (cmd_full_path);
		}
		free(cmd_full_path);
		i++;
	}
	ft_free_char_tab(sep_env_paths);
	return (cmd);
}
