/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deymons <deymons@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 17:23:03 by deymons           #+#    #+#             */
/*   Updated: 2024/04/18 16:29:39 by deymons          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

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
		if (!ft_strncmp(envp_key, "PATH", 4))
		{
			free(envp_key);
			return (envp->envar + i + 1);
		}
		free(envp_key);
		envp = envp->next;
	}
	return (NULL);
}

char	*get_path(t_cmd *cmd, t_envp *envp)
{
		char	**sep_env_paths;
		char	*tmp_path;
		char	*cmd_path;
		int		i;

		sep_env_paths = ft_split(fetch_path_from_envp(envp), ':');
		if (!sep_env_paths || !sep_env_paths[0])
		{
			printf("\t\tminishell: PATH not found in envp\n");
			return (NULL);
		}
		i = 0;
		while (sep_env_paths[i])
		{
			tmp_path = ft_strjoin(sep_env_paths[i], "/");
			cmd_path = ft_strjoin(tmp_path, cmd->cmd_and_args[0]);
			free(tmp_path);
			if (access(cmd_path, F_OK | X_OK) == 0)
			{
				printf("\t\tcommand found at: %s\n", cmd_path);
				ft_free_char_tab(sep_env_paths);
				return (cmd_path);
			}
			i++;
		}
	return (cmd->cmd_and_args[0]);
}
