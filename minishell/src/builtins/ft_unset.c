/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwintgen <rwintgen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 15:04:51 by rwintgen          #+#    #+#             */
/*   Updated: 2024/05/15 13:41:59 by rwintgen         ###   ########.fr       */
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
			if (!ft_strcmp(tmp->key, cmd->cmd_and_args[i]))
			{
				if (tmp->prev)
					tmp->prev->next = tmp->next;
				if (tmp->next)
					tmp->next->prev = tmp->prev;
				if (tmp == *envp)
					*envp = tmp->next;
				free(tmp->key);
				free(tmp->value);
				free(tmp);
				break ;
			}
			tmp = tmp->next;
		}
		i++;
	}
	return (SUCCESS);
}
