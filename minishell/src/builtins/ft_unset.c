/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwintgen <rwintgen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 15:04:51 by rwintgen          #+#    #+#             */
/*   Updated: 2024/05/09 11:51:50 by rwintgen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_unset(t_cmd *cmd, t_envp **envp)
{
	t_envp	*tmp;
	int		i;

	i = 1;
	while (cmd->cmd_and_args[i])
	{
		tmp = *envp;
		while (tmp)
		{
			if (!ft_strncmp(tmp->key, cmd->cmd_and_args[i], ft_strlen(cmd->cmd_and_args[i])))
			{
				free(tmp->key);
				free(tmp->value);
				tmp->key = NULL;
				tmp->value = NULL;
				break ;
			}
			tmp = tmp->next;
		}
		i++;
	}
	return (0);
}
