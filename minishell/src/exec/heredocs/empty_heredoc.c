/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   empty_heredoc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwintgen <rwintgen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 13:52:27 by deymons           #+#    #+#             */
/*   Updated: 2024/05/09 12:42:29 by rwintgen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// checks if heredoc is missing a command
bool	missing_heredoc_cmd(t_arg *arg)
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

// adds heredoc delimiter to the command
char	**add_delimiter(t_arg *cmd)
{
	char	**result;

	result = malloc(sizeof(char *) * 3);
	if (!result)
	{
		ft_putendl_fd(E_MALLOC, STDERR_FILENO);
		return (NULL);
	}
	result[0] = ft_strdup("chibron");
	result[1] = ft_strdup(cmd->prev->str_command);
	result[2] = NULL;
	return (result);
}
