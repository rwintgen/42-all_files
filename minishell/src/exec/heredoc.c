/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deymons <deymons@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 14:36:32 by deymons           #+#    #+#             */
/*   Updated: 2024/04/19 15:59:34 by deymons          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

// checks if current line is the delimiter
int	check_eof(char *line, char *delimiter)
{
	if (!line)
	{
		ft_putstr_fd("minishell: warning: here-document delimited by end-of-file (wanted '", STDERR_FILENO);
		ft_putstr_fd(delimiter, STDERR_FILENO);
		ft_putendl_fd("')", STDERR_FILENO);
		return (1);
	}
	else if (!ft_strncmp(line, delimiter, INT_MAX))
		return (1);
	else
		return (0);
}

// creates a temp file with new name
int create_tmp_file(char **file)
{
	static char	filename[200];
	char		*id_str;
	int			fd;
	int			i;

	id_str = NULL;
	i = 0;
	while (true)
	{
		ft_strlcpy(filename, "/tmp/.heredoc", 14);
		id_str = ft_itoa(i++);
		if (ft_strlen(filename) + ft_strlen(id_str) + 1 < sizeof(filename))
		{
			ft_strlcat(filename + 11, id_str, sizeof(filename) - 14);
			free(id_str);
			ft_open(filename, &fd, FLAG_TMP);
			if (fd >= 0)
			{
				*file = strdup(filename);
				return (fd);
			}
		}
		else
			break;
	}
	free(id_str);
	return (-1);
}

// handles writing in tmp file
char	*heredoc_handler(char *delimiter)
{
	char	*line;
	char	*file;
	int		fd;

	line = NULL;
	file = NULL;
	fd = create_tmp_file(&file);
	while (true)
	{
		line = readline("> ");
		if (check_eof(line, delimiter))
			break ;
		ft_putendl_fd(line, fd);
		free(line);
	}
	free(line);
	close(fd);
	return (file);
}
