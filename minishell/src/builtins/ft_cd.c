/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwintgen <rwintgen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 02:42:25 by amalangi          #+#    #+#             */
/*   Updated: 2024/04/29 12:46:43 by rwintgen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*get_home(t_envp *envp)
{
	t_envp	*tmp;

	tmp = envp;
	while (tmp)
	{
		if (!ft_strncmp(tmp->key, "HOME", 5))
			return (tmp->value);
		tmp = tmp->next;
	}
	ft_putstr_fd("minishell: cd: HOME not set\n", 2);
	return (NULL);
}

char	*get_old_cwd(t_envp *envp)
{
	t_envp	*tmp;

	tmp = envp;
	while (tmp)
	{
		if (!ft_strncmp(tmp->key, "OLDPWD", 7))
			return (tmp->value);
		tmp = tmp->next;
	}
	ft_putstr_fd("minishell: cd: OLDPWD not set\n", 2);
	return (NULL);
}

void	update_old_cwd(t_envp *envp, char *old_cwd)
{
	t_envp	*tmp;

	tmp = envp;
	while (tmp)
	{
		if (!ft_strncmp(tmp->key, "OLDPWD", 7))
		{
			free(tmp->value);
			tmp->value = ft_strdup(old_cwd);
			return ;
		}
		tmp = tmp->next;
	}
}

void	update_cwd(t_envp *envp, char *new_cwd)
{
	t_envp	*tmp;

	tmp = envp;
	while (tmp)
	{
		if (!ft_strncmp(tmp->key, "PWD", 4))
		{
			free(tmp->value);
			tmp->value = ft_strdup(new_cwd);
			return ;
		}
		tmp = tmp->next;
	}
}

int	ft_cd(t_cmd *cmd, t_envp *envp)
{
	char	*new_cwd;
	char	*old_cwd;


	if (cmd->cmd_and_args[2])
	{
		ft_putstr_fd("minishell: cd: too many arguments\n", 2);
		return (1);
	}
	if (!cmd->cmd_and_args[1] || !ft_strncmp(cmd->cmd_and_args[1], "~", 2))
	{
		new_cwd = get_home(envp);
		if (!new_cwd)
			return (1);
	}
	// else if (!ft_strncmp(cmd->cmd_and_args[1], "-", 2))
	// {
	// 	old_cwd = get_old_cwd(envp);
	// 	if (old_cwd == NULL)
	// 		return (1);
	// 	new_cwd = old_cwd;
	// }
	else
		new_cwd = cmd->cmd_and_args[1];
	if (chdir(new_cwd) == -1)
	{
		ft_putstr_fd("minishell: cd: ", 2);
		ft_putstr_fd(new_cwd, 2);
		ft_putstr_fd(": ", 2);
		ft_putstr_fd(strerror(errno), 2);
		ft_putstr_fd("\n", 2);
		return (1);
	}
	old_cwd = get_old_cwd(envp);
	if (old_cwd == NULL)
		return (1);
	update_old_cwd(envp, old_cwd);
	update_cwd(envp, new_cwd);
	return (0);
}
