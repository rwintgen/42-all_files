/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwintgen <rwintgen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 17:23:03 by deymons           #+#    #+#             */
/*   Updated: 2024/05/30 15:18:36 by rwintgen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*fetch_path_from_envp(t_envp *envp);
static void	join_path(char **cmd_path, char *sep_env_path, char *cmd);

// fetches the path of the command to execute
char	*get_path(t_cmd *cmd, t_envp *envp)
{
	char	**sep_env_paths;
	char	*cmd_path;
	int		i;

	sep_env_paths = ft_split(fetch_path_from_envp(envp), ':');
	if (!sep_env_paths || !sep_env_paths[0])
		return (cmd->cmd_and_args[0]);
	i = 0;
	while (sep_env_paths[i])
	{
		join_path(&cmd_path, sep_env_paths[i], cmd->cmd_and_args[0]);
		if (access(cmd_path, F_OK | X_OK) == SUCCESS)
		{
			ft_free_char_tab(sep_env_paths);
			return (cmd_path);
		}
		free(cmd_path);
		i++;
	}
	ft_free_char_tab(sep_env_paths);
	return (cmd->cmd_and_args[0]);
}

// fetches the PATH value from envp
static char	*fetch_path_from_envp(t_envp *envp)
{
	int		i;
	char	*envp_key;

	i = 0;
	envp_key = NULL;
	while (envp)
	{
		i = 0;
		while (envp->envar[i] && envp->envar[i] != '=')
			i++;
		envp_key = ft_substr(envp->envar, 0, i);
		if (!ft_strcmp(envp_key, "PATH"))
		{
			free(envp_key);
			return (envp->envar + i + 1);
		}
		free(envp_key);
		envp = envp->next;
	}
	return (NULL);
}

static void	join_path(char **cmd_path, char *sep_env_path, char *cmd)
{
	char	*tmp_path;

	tmp_path = ft_strjoin(sep_env_path, "/");
	*cmd_path = ft_strjoin(tmp_path, cmd);
	free(tmp_path);
}
