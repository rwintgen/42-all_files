/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwintgen <rwintgen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 15:04:51 by rwintgen          #+#    #+#             */
/*   Updated: 2024/05/24 18:02:06 by rwintgen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	free_node(t_envp *node, t_envp **envp);

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
				free_node(tmp, envp);
				break ;
			}
			tmp = tmp->next;
		}
		i++;
	}
	return (SUCCESS);
}

static void	free_node(t_envp *node, t_envp **envp)
{
	if (node->prev)
		node->prev->next = node->next;
	if (node->next)
		node->next->prev = node->prev;
	if (node == *envp)
		*envp = node->next;
	free(node->key);
	free(node->value);
	free(node->envar);
	free(node);
}
