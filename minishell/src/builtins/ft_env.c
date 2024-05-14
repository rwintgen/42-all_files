/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwintgen <rwintgen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 15:02:13 by rwintgen          #+#    #+#             */
/*   Updated: 2024/05/14 15:13:18 by rwintgen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_env(char *arg, t_envp *envp)
{
	t_envp	*tmp;

	if (arg && ft_strcmp(arg, "env"))
	{
		ft_putendl_fd(E_ENV_ARGC, STDERR_FILENO);
		return (FAILURE);
	}
	tmp = envp;
	while (tmp)
	{
		if (tmp->value)
		{
			ft_putstr_fd(tmp->key, STDOUT_FILENO);
			ft_putstr_fd("=", STDOUT_FILENO);
			ft_putendl_fd(tmp->value, STDOUT_FILENO);
		}
		tmp = tmp->next;
	}
	return (SUCCESS);
}
