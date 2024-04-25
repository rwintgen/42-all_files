/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwintgen <rwintgen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 02:42:25 by amalangi          #+#    #+#             */
/*   Updated: 2024/04/25 15:57:44 by rwintgen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_cd(t_cmd *cmd, t_envp *envp)
{
	char	*old_pwd;
	char	*new_pwd;

	old_pwd = NULL;
	new_pwd = NULL;
	if (get_new_pwd(cmd, envp, &old_pwd) == -1)
		return (1);
	old_pwd = get_old_pwd(envp);
	update_pwd(envp, new_pwd);
	update_old_pwd(envp, old_pwd);
	return (0);
}

int	get_new_pwd(t_cmd *cmd, t_envp *envp, char **new_pwd)
{
	*new_pwd = cmd->cmd_and_args[1];
	if (!*new_pwd || !**new_pwd || !ft_strncmp(*new_pwd, "~", 2))
	{
		while (envp && ft_strncmp(envp->key, "HOME", 5))
			envp = envp->next;
		*new_pwd = envp->value;
	}
	if (chdir(*new_pwd) == -1)
	{
		ft_putstr_fd("minishell: cd: ", STDERR_FILENO);
		ft_putstr_fd(*new_pwd, STDERR_FILENO);
		ft_putendl_fd(": no such file or directory", STDERR_FILENO);
		return (-1);
	}
	return (0);
}

char	*get_old_pwd(t_envp *envp)
{
	while (envp)
	{
		if (ft_strncmp(envp->key, "OLDPWD", 7) == 0)
			return (envp->value);
		envp = envp->next;
	}
	return (ft_strdup(""));
}

void	update_pwd(t_envp *envp, char *new_pwd)
{
	free(envp->envar);
	free(envp->value);
	envp->envar = ft_strjoin("PWD=", new_pwd);
	envp->value = new_pwd;
}

void	update_old_pwd(t_envp *envp, char *old_pwd)
{
	while (envp && ft_strncmp(envp->key, "OLDPWD", 7))
		envp = envp->next;
	free(envp->envar);
	free(envp->value);
	envp->envar = ft_strjoin("OLDPWD=", old_pwd);
	envp->value = old_pwd;
}
