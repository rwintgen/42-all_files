/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwintgen <rwintgen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 17:16:03 by rwintgen          #+#    #+#             */
/*   Updated: 2024/05/14 12:50:49 by rwintgen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*get_home(t_envp *envp)
{
	t_envp	*tmp;

	tmp = envp;
	while (tmp)
	{
		if (!ft_strcmp(tmp->key, "HOME"))
			return (tmp->value);
		tmp = tmp->next;
	}
	ft_putstr_fd("minishell: cd: HOME not set\n", 2);
	return (NULL);
}

char	*get_cwd(void)
{
	char	*cwd;

	cwd = getcwd(NULL, 0);
	if (!cwd)
	{
		ft_putstr_fd("minishell: error retrieving current directory\n", 2);
	}
	return (cwd);
}

void	update_old_cwd(t_envp *envp, char *old_cwd)
{
	t_envp	*tmp;

	tmp = envp;
	while (tmp)
	{
		if (!ft_strcmp(tmp->key, "OLDPWD"))
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
		if (!ft_strcmp(tmp->key, "PWD"))
		{
			free(tmp->value);
			tmp->value = ft_strdup(new_cwd);
			return ;
		}
		tmp = tmp->next;
	}
}

int	err_msg_cd(char *old_cwd, char *new_cwd)
{
	ft_putstr_fd("minishell: cd: ", STDERR_FILENO);
	ft_putstr_fd(new_cwd, STDERR_FILENO);
	ft_putstr_fd(": ", STDERR_FILENO);
	ft_putstr_fd(strerror(errno), STDERR_FILENO);
	ft_putstr_fd("\n", STDERR_FILENO);
	free(old_cwd);
	return (1);
}
