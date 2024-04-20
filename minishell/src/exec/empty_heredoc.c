/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   empty_heredoc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwintgen <rwintgen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 13:52:27 by deymons           #+#    #+#             */
/*   Updated: 2024/04/20 11:30:25 by rwintgen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

char	**add_delimiter(t_arg *cmd)
{
	char	**result;

	result = malloc(sizeof(char *) * 2);
	if (!result)
	{
		ft_putstr_fd("minishell: malloc error\n", STDERR_FILENO);
		return (NULL);
	}
	result[0] = ft_strdup("chibron");
	result[1] = ft_strdup(cmd->prev->str_command);
	result[2] = NULL;
	return (result);
}

// checks if heredoc is missing a command
int	missing_heredoc_cmd(t_arg *arg)
{
	while (arg->prev && arg->prev->type != PIPE)
		arg = arg->prev;
	while (arg && arg->type != PIPE)
	{
		if (arg->type == CMD)
			return (false);
		arg = arg->next;
	}
	return (true);
}

// adds a node in t_arg for handling empty heredoc cmd
void	create_heredoc_cmd(t_arg *elem)
{
	t_arg	*new_node;

	new_node = malloc(sizeof(t_arg));
	new_node->str_command = ft_strdup("heredoc");
	new_node->type = CMD;
	new_node->prev = elem;
	new_node->next = elem->next;
	elem->next = new_node;
}

