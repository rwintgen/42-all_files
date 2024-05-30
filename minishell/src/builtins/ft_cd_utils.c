/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwintgen <rwintgen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 17:16:03 by rwintgen          #+#    #+#             */
/*   Updated: 2024/05/30 17:03:30 by rwintgen         ###   ########.fr       */
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
	print_err(E_CD_HOME, NULL, NULL, NULL);
	return (NULL);
}

char	*get_cwd(void)
{
	char	*cwd;

	cwd = getcwd(NULL, 0);
	if (!cwd)
		print_err(E_CD_DIR, NULL, NULL, NULL);
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

void	update_cwd(t_envp *envp)
{
	t_envp	*tmp;

	tmp = envp;
	while (tmp)
	{
		if (!ft_strcmp(tmp->key, "PWD"))
		{
			free(tmp->value);
			tmp->value = getcwd(NULL, 0);
			return ;
		}
		tmp = tmp->next;
	}
}

int	err_msg_cd(char *old_cwd, char *new_cwd)
{
	print_err("minishell: cd: ", new_cwd, ": ", strerror(errno));
	free(old_cwd);
	return (FAILURE);
}
