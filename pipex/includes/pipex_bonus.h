/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwintgen <rwintgen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 18:34:47 by rwintgen          #+#    #+#             */
/*   Updated: 2024/04/02 18:05:44 by rwintgen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include <sys/types.h>
# include <sys/wait.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include "../libft/libft.h"

typedef enum e_err
{
	ERR_ARGC,
	ERR_INFILE,
	ERR_OUTFILE,
	ERR_PIPE,
	ERR_FORK,
	ERR_EXEC,
	ERR_CMD,
	ERR_HEREDOC
}	t_err;

typedef enum e_mod
{
	FLAG_READ,
	FLAG_WRITE,
	FLAG_HEREDOC
}	t_mod;

typedef struct s_data
{
	int		filefd[2];
	int		pipefd[2];

	int		argc;
	char	**argv;
	char	**envp;
}	t_data;

int		err_msg(int err_id);
int		ft_open(char *file, int *fd, int flag);
int		check_argc(int argc, char **argv);
char	*ft_get_path(char *cmd, char **envp);
int		unlink_err(char *file);
int		handle_heredoc(char **argv, int *filefd);
void	set_inf_outf_fds(int *filefd, int argc, char **argv, int arg_cursor);
void	exec_piped_commands(int arg_cursor, t_data data);
void	ft_wait_all(void);

#endif
