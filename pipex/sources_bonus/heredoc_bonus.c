/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwintgen <rwintgen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 15:33:25 by rwintgen          #+#    #+#             */
/*   Updated: 2024/04/02 18:06:23 by rwintgen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex_bonus.h"

int	unlink_err(char *file)
{
	unlink(file);
	return (err_msg(ERR_HEREDOC));
}

int	check_eof(char *line, char *delimiter)
{
	if (!line)
		return (1);
	else if (!ft_strncmp(line, delimiter, ft_strlen(delimiter)) && \
				line[ft_strlen(delimiter)] == '\n')
		return (1);
	else
		return (0);
}

int	handle_heredoc(char **argv, int *filefd)
{
	int		hd_buf_fd;
	char	*line;

	if (ft_strcmp(argv[1], "here_doc") != 0)
		return (0);
	else
	{
		if (ft_open(".heredoc_buf", &hd_buf_fd, FLAG_HEREDOC) < 0)
			exit(err_msg(ERR_HEREDOC));
		while (1)
		{
			write(1, "heredoc> ", 9);
			line = get_next_line(0);
			if (check_eof(line, argv[2]))
				break ;
			ft_putstr_fd(line, hd_buf_fd);
			free(line);
		}
		free(line);
		close(hd_buf_fd);
		if (ft_open(".heredoc_buf", filefd, FLAG_READ) < 0)
			exit(unlink_err(".heredoc_buf"));
	}
	return (1);
}
