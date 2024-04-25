/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwintgen <rwintgen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 14:36:32 by deymons           #+#    #+#             */
/*   Updated: 2024/04/25 12:47:35 by rwintgen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

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

// creates a temp file with new name
int	create_tmp_file(char **file)
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
			if (try_file(filename, id_str, &fd, file))
				return (fd);
		}
		else
			break ;
	}
	free(id_str);
	return (-1);
}

// tries to create a file with a new name
bool	try_file(char *base_filename, char *id_str, int *fd, char **file)
{
	static char	filename[200];

	ft_strlcpy(filename, base_filename, sizeof(filename));
	ft_strlcat(filename, id_str, sizeof(filename));
	ft_open(filename, fd, FLAG_TMP);
	if (*fd >= 0)
	{
		*file = strdup(filename);
		return (true);
	}
	return (false);
}

// checks if current line is the delimiter
bool	check_eof(char *line, char *delimiter)
{
	if (!line)
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
