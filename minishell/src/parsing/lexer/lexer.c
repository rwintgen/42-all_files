/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwintgen <rwintgen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 12:27:41 by rwintgen          #+#    #+#             */
/*   Updated: 2024/04/27 17:34:04 by rwintgen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	lexer_v2(t_arg *head)
{
	set_spec(head);
	set_file(head);
	set_cmd(head);
	set_arg(head);
}

void	set_spec(t_arg *elem)
{
	while (elem)
	{
		if (ft_strncmp(elem->str_command, "<<", 2) == 0)
			elem->type = HEREDOC;
		else if (ft_strncmp(elem->str_command, "<", 1) == 0)
			elem->type = INPUT;
		else if (ft_strncmp(elem->str_command, ">>", 2) == 0)
			elem->type = APPEND;
		else if (ft_strncmp(elem->str_command, ">", 1) == 0)
			elem->type = OUTPUT;
		else if (ft_strncmp(elem->str_command, "|", 1) == 0)
			elem->type = PIPE;
		elem = elem->next;
	}
}

void	set_file(t_arg *elem)
{
	while (elem)
	{
		if (elem->prev && elem->prev->type == INPUT)
			elem->type = INFILE;
		else if (elem->prev && elem->prev->type == OUTPUT)
			elem->type = OUTFILE;
		else if (elem->prev && elem->prev->type == APPEND)
			elem->type = OUTFILE;
		else if (elem->prev && elem->prev->type == HEREDOC)
			elem->type = DELIM;
		elem = elem->next;
	}
}

void	set_cmd(t_arg *elem)
{
	while (elem->next)
		elem = elem->next;
	while (elem)
	{
		if (elem->type == -1 && (!elem->prev || elem->prev->type >= 0))
			elem->type = CMD;
		elem = elem->prev;
	}
}

void	set_arg(t_arg *elem)
{
	t_arg	*tmp;
	int		cmd_count;

	tmp = elem;
	while (tmp)
	{
		if (tmp->type == -1 && tmp->str_command[0] == '-')
			tmp->type = OPTION;
		else if (tmp->type == -1 && tmp->str_command[0] != '-')
			tmp->type = ARG;
		tmp = tmp->next;
	}
	cmd_count = 0;
	while (elem && elem->type != PIPE)
	{
		if (elem->type == CMD)
			cmd_count++;
		if (elem->type == CMD && cmd_count > 1)
				elem->type = ARG;
		elem = elem->next;
	}
}
