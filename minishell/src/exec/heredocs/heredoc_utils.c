/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwintgen <rwintgen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 15:30:54 by rwintgen          #+#    #+#             */
/*   Updated: 2024/05/13 16:50:54 by rwintgen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// checks if last command is a heredoc
bool	last_cmd_is_heredoc(t_arg *arg)
{
	while (arg && arg->next)
		arg = arg->next;
	while (arg && arg->prev && arg->type != PIPE)
	{
		if (arg->type == DELIM)
			return (true);
		arg = arg->prev;
	}
	return (false);
}

// checks if current line is the delimiter
bool	check_eof(char *line, char *delimiter)
{
	if (!line && g_sig != SIGINT)
	{
		ft_putstr_fd(E_DELIM, STDERR_FILENO);
		ft_putstr_fd(delimiter, STDERR_FILENO);
		ft_putendl_fd("')", STDERR_FILENO);
		return (true);
	}
	else if (!ft_strncmp(line, delimiter, INT_MAX))
		return (true);
	else
		return (false);
}