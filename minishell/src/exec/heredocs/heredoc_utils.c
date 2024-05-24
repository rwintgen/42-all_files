/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwintgen <rwintgen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 15:30:54 by rwintgen          #+#    #+#             */
/*   Updated: 2024/05/24 14:31:31 by rwintgen         ###   ########.fr       */
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
		print_err(E_DELIM, delimiter, "')", NULL);
		return (true);
	}
	else if (!ft_strncmp(line, delimiter, ft_strlen(delimiter) + 1))
		return (true);
	else
		return (false);
}

// unlinks heredoc file if it exists
void	unlink_heredoc_file(char *heredoc_file)
{
	if (heredoc_file)
	{
		unlink(heredoc_file);
		free(heredoc_file);
	}
}
