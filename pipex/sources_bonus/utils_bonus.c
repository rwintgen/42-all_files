/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwintgen <rwintgen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 16:20:13 by rwintgen          #+#    #+#             */
/*   Updated: 2024/04/02 18:06:44 by rwintgen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex_bonus.h"

int	check_argc(int argc, char **argv)
{
	int	min_arg;

	min_arg = 5;
	if (argv[1] && !ft_strcmp(argv[1], "here_doc"))
		min_arg++;
	if (argc < min_arg)
		return (0);
	return (1);
}

int	err_msg(int err_id)
{
	if (err_id == ERR_ARGC)
		ft_putstr_fd("pipex: need more arguments\n", 2);
	if (err_id == ERR_INFILE)
		ft_putstr_fd("pipex: can't access infile\n", 2);
	if (err_id == ERR_OUTFILE)
		ft_putstr_fd("pipex: can't access outfile\n", 2);
	if (err_id == ERR_PIPE)
		ft_putstr_fd("pipex: pipe failed\n", 2);
	if (err_id == ERR_FORK)
		ft_putstr_fd("pipex: fork failed\n", 2);
	if (err_id == ERR_EXEC)
		ft_putstr_fd("pipex: command not found: ", 2);
	if (err_id == ERR_CMD)
		ft_putstr_fd("pipex: need valid command\n", 2);
	if (err_id == ERR_HEREDOC)
		ft_putstr_fd("pipex: heredoc error\n", 2);
	return (err_id);
}

static char	*ft_find_env_path(char **envp)
{
	int		i;
	int		j;
	char	*envp_name;

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
	while (sep_env_paths && sep_env_paths[i])
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

void	ft_wait_all(void)
{
	int	status;

	while (wait(&status) > 0)
	{
	}
}
