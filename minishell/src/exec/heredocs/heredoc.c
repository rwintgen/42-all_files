/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwintgen <rwintgen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 14:36:32 by deymons           #+#    #+#             */
/*   Updated: 2024/05/13 17:07:36 by rwintgen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// invoques the heredoc in the child process
void prompt_heredoc(char *delimiter, int fd, char *file, t_sh *tofree)
{
	char	*line;

	line = NULL;
	signal(SIGINT, sigint_heredoc);
	while (g_sig != SIGINT)
	{
		line = readline("> ");
		if (check_eof(line, delimiter))
			break ;
		ft_putendl_fd(line, fd);
		free(line);
	}
	free(line);
	close_all_fds();
	if (g_sig == SIGINT)
	{
		unlink(file);
		free(file);
		free_sh(tofree);
		exit(130);
	}
	free(file);
	exit(free_sh(tofree));
}

// handles writing in tmp file
char	*heredoc_handler(char *delimiter, t_sh *sh)
{
	char	*file;
	int		pid;
	int		fd;
	int		status;

	file = NULL;
	fd = create_tmp_file(&file);
	pid = fork();
	if (pid == 0)
		prompt_heredoc(delimiter, fd, file, sh);
	else
		waitpid(pid, &status, 0);
	if (WIFEXITED(status))
    	sh->exit_code = exit_code_handler(errno, status);
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
			{
				free(id_str);
				return (fd);
			}
		}
		else
			break ;
		free(id_str);
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
		*file = ft_strdup(filename);
		return (true);
	}
	free(*file);
	return (false);
}
