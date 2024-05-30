/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   empty_heredoc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwintgen <rwintgen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 13:52:27 by deymons           #+#    #+#             */
/*   Updated: 2024/05/30 16:01:51 by rwintgen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static bool	missing_heredoc_cmd(t_arg *arg);
static void	create_heredoc_cmd(t_arg *elem);

// creates heredoc command for parsing if needed
void	create_missing_heredoc_cmd(t_arg *arg)
{
	while (arg)
	{
		if (arg->type == DELIM && missing_heredoc_cmd(arg))
			create_heredoc_cmd(arg);
		arg = arg->next;
	}
}

// checks if heredoc is missing a command
static bool	missing_heredoc_cmd(t_arg *arg)
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
static void	create_heredoc_cmd(t_arg *elem)
{
	t_arg	*new_node;

	new_node = malloc(sizeof(t_arg));
	if (!new_node)
	{
		ft_putendl_fd(E_MALLOC, STDERR_FILENO);
		return ;
	}
	new_node->str_command = ft_strdup("heredoc");
	new_node->type = CMD;
	new_node->prev = elem;
	new_node->next = elem->next;
	elem->next = new_node;
}
