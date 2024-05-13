/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwintgen <rwintgen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 14:36:32 by deymons           #+#    #+#             */
/*   Updated: 2024/05/13 15:43:03 by rwintgen         ###   ########.fr       */
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

// ctrl+C handler for heredoc
void sigint_heredoc(int sig)
{
	(void)sig;
	g_sig = SIGINT;
	close(STDIN_FILENO);
}

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
	close(fd); // TODO close all fds?
	if (g_sig == SIGINT)
	{
		unlink(file);
		free(file);
		free_sh(tofree);
		exit(130);
	}
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
	printf("heredoc_handler exit_code: %d\n", sh->exit_code);
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
