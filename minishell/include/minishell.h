/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwintgen <rwintgen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 17:11:52 by amalangi          #+#    #+#             */
/*   Updated: 2024/04/22 16:47:21 by rwintgen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <limits.h>
# include <fcntl.h>
# include <sys/stat.h>
# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdbool.h>
# include <sys/types.h>
# include <sys/wait.h>
# include "../libft/src/libft.h"
# include <signal.h>
# include <errno.h>

extern int	g_sig;

// TOKENS
typedef enum	e_tokens
{
	INFILE,
	OUTFILE,
	INPUT, // "<"
	HEREDOC, // "<<"
	DELIM, // delimiter
	OUTPUT, // ">"
	APPEND, // ">>"
	PIPE, // "|"
	CMD, // command
	ARG, // argument
	OPTION // option
}				t_tokens;

// OPEN FLAGS
typedef enum	e_mod
{
	FLAG_READ,
	FLAG_HEREDOC,
	FLAG_WRITE,
	FLAG_APPEND,
	FLAG_TMP
}				t_mod;

// ERRORS
typedef enum	e_err
{
	ERR_OPEN,
	ERR_PIPE,
	ERR_FORK,
	ERR_EXEC,
	ERR_HEREDOC
}				t_err;

// CMD LINE WORDS
typedef struct	s_arg
{
    char			*str_command;
    int				type;

    struct s_arg	*prev;
    struct s_arg	*next;
}				t_arg;

// EXEC READY DATA STRUCT
typedef struct	s_cmd
{
	char			**cmd_and_args;

	int				input_fd;
	int				output_fd;

	bool			skip_cmd;
	bool			is_builtin;

	struct s_cmd	*next;
	struct s_cmd	*prev;
}					t_cmd;

// ENVP COPY
typedef struct	s_envp
{
	char	*envar;
	char	*key;
	char	*value;

	struct s_envp	*prev;
	struct s_envp	*next;
}				t_envp;

// SH STRUCT
typedef struct	s_sh
{
	struct s_arg		*arg;
	struct s_cmd		*cmd;
	struct s_envp		*envp;

	int					saved_stdfd[2];
	int					pipefd[2];
	int					exit_code;
}				t_sh;

void	print_t_arg_struct(t_arg *data);
void	print_t_cmd_struct(t_cmd *cmd);

// parsing
char	*get_var(char *key, t_envp *envp);
int		empty_line(char *input);
t_arg	*copy_args(char *input);
int		open_quote(char *input);
char	*replace_dollar(char *input, t_envp *envp, int exit_code);
void	free_tab(char **tab);
void	free_s_cmd_line(t_arg *data);
int		lexer(char **str, int i, t_arg *data);
int		is_special_char(char c);
char	*true_line(char *str, t_sh *sh);
t_envp	*save_envp(char **env);
char	**restore_envp(t_envp *env);
void	parse_input(char *input, t_sh *sh);

void	sig_quit_state(int sig);
void	sig_int_state(int sig);
int		ft_echo(t_cmd *cmd, t_envp *envp);
int		ft_cd(t_cmd *cmd, t_envp *envp);
int		ft_pwd(void);


// exec de chameau
char	*get_path(t_cmd *cmd, t_envp *envp);
void	exec_handler(t_sh *sh);
int		ft_open(char *file, int *fd, int flag);
void	save_stdfd(int saved_stdfd[2]);
void	save_commands(t_sh *sh);
int		set_infile(t_arg *cmd, int stdfd_in, int pipefd_in);
int		set_outfile(t_arg *cmd, int stdfd_out, int pipefd_out);
void	exec_commands(t_sh *sh);
void	ft_wait_all(void);
int		count_commands(t_cmd *cmd);
int		current_command(t_cmd *cmd);
int		last_cmd(t_arg *arg);
bool	is_builtin(char *cmd);
int		create_tmp_file(char **file);
char	*heredoc_handler(char *delimiter);
char	*empty_heredoc_handler(char *delimiter, int fd);
int		check_eof(char *line, char *delimiter);
void	free_node(t_cmd *node);
void	redirect_io(t_cmd *cmd);
void	close_all_fds(t_cmd *cmd);
char	**add_delimiter(t_arg *cmd);
bool	missing_heredoc_cmd(t_arg *arg);
void	create_heredoc_cmd(t_arg *elem);
void	set_exit_status(int sig, t_envp **envp);
int		is_not_found_cmd(char *str_command, t_envp *envp);
void	go_to_start_of_block(t_arg **cmd);
void	check_inf_pipe(t_arg *to_check, t_arg **true_infile);
bool	check_inf_delim(t_arg *to_check, char **heredoc_file);
void	check_inf_infile(t_arg *to_check, t_arg **true_infile);
int		set_inf_fd(char *hd_file, t_arg *true_infile, int pfd_in, int stdfd_in);
int		count_redir_out(t_arg *cmd);
void	create_outfiles(t_arg *cmd);
bool	check_outf_outfile(t_arg *cmd, t_arg **true_outfile);
void	check_outf_pipe(t_arg *cmd, t_arg **true_outfile);
int		set_outf_fd(t_arg	*true_outfile, int pfd_out, int stdfd_out);
void	append_env_node(t_envp **env_cpy, char *env_var);
int		exec_builtin(t_cmd *cmd, t_envp *envp);
void	close_saved_fds(int saved_stdfd[2]);
bool	infiles_ok(t_arg *cmd);
void	sigint_muted(int signal);
int		free_sh(t_sh *sh);
int		set_exit_code(int error_code);
void	free_arg(t_arg *arg);
void	free_cmd(t_cmd *cmd);
void	free_envp(t_envp *envp);
void	close_if_valid(int fd);
void	redirect_io_nofork(t_sh *sh, t_cmd *cmd);
void	restore_io_nofork(t_sh *sh, t_cmd *cmd);

#endif