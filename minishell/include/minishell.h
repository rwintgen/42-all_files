/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwintgen <rwintgen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 17:11:52 by amalangi          #+#    #+#             */
/*   Updated: 2024/05/30 17:57:46 by rwintgen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

/************************* LIBRARIES ************************/

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
# include "../libft/libft.h"
# include <signal.h>
# include <errno.h>

/************************** DEFINES *************************/

# define E_SYNTAX_REDIR "minishell: syntax error near angle brackets"
# define E_SYNTAX_PIPE "minishell: syntax error near pipe"
# define E_SYNTAX_QUOTE "minishell: syntax error near quote"
# define E_SYNTAX_NL "minishell: syntax error near newline"

# define E_FILE_OPEN "minishell: error opening file: "
# define E_FILE_EXIST "minishell: no such file or directory: "
# define E_FILE_PERM "minishell: permission denied: "
# define E_FILE_DIR "minishell: is a directory: "

# define E_CMD_NF "minishell: command not found: "

# define E_EXPORT_ID "minishell: export: not a valid identifier: "
# define E_EXIT_ARGC "minishell: exit: too many arguments"
# define E_EXIT_NUM "minishell: exit: numeric argument required"

# define E_ENV_ARGC "minishell: env: too many arguments"

# define E_MALLOC "minishell: malloc error"
# define E_PIPE "minishell: pipe error"
# define E_FORK "minishell: fork error"

# define E_DELIM "minishell: warning: here-document delimited by \
end-of-file (wanted '"

# define E_CD_HOME "minishell: cd: HOME not set"
# define E_CD_DIR "minishell: error retrieving current directory"
# define E_CD_ARGC "minishell: cd: too many arguments"

# define EMPTY_HEREDOC "empty_heredoc_file"

# define INT_64_MAX "9223372036854775807"
# define INT_64_MIN "9223372036854775808"

# define CTRLC -130
# define ERROR -1
# define SUCCESS 0
# define FAILURE 1

/********************** GLOBAL VARIABLE *********************/

extern int	g_sig;

/************************ STRUCTURES ************************/

// TOKENS
typedef enum e_tokens
{
	INFILE,
	OUTFILE,
	INPUT,
	HEREDOC,
	DELIM,
	OUTPUT,
	APPEND,
	PIPE,
	CMD,
	ARG,
	OPTION,
	REDIR
}				t_tokens;

// OPEN FLAGS
typedef enum e_mod
{
	FLAG_READ,
	FLAG_HEREDOC,
	FLAG_WRITE,
	FLAG_APPEND,
	FLAG_TMP
}				t_mod;

// ERRORS
typedef enum e_err
{
	ERR_OPEN,
	ERR_PIPE,
	ERR_FORK,
	ERR_EXEC,
	ERR_HEREDOC
}				t_err;

// CMD LINE WORDS
typedef struct s_arg
{
	char			*str_command;
	int				type;

	struct s_arg	*prev;
	struct s_arg	*next;
}				t_arg;

// EXEC READY DATA STRUCT
typedef struct s_cmd
{
	char			**cmd_and_args;

	int				input_fd;
	int				output_fd;

	bool			is_builtin;

	struct s_cmd	*next;
	struct s_cmd	*prev;
}					t_cmd;

// ENVP COPY
typedef struct s_envp
{
	char			*envar;
	char			*key;
	char			*value;

	bool			is_printed;

	struct s_envp	*prev;
	struct s_envp	*next;
}				t_envp;

// SH STRUCT
typedef struct s_sh
{
	struct s_arg		*arg;
	struct s_cmd		*cmd;
	struct s_envp		*envp;

	int					saved_stdfd[2];
	int					pipefd[2];
	int					exit_code;
}				t_sh;

/************************ PROTOTYPES ************************/

void	print_t_arg_struct(t_arg *data);
void	print_t_cmd_struct(t_cmd *cmd);

	///// BUILTINS /////

int		exec_builtin(t_cmd *cmd, t_envp **envp, t_sh *sh);
bool	is_builtin(char *cmd);

int		ft_cd(t_cmd *cmd, t_envp *envp);
char	*get_home(t_envp *envp);
char	*get_cwd(void);
void	update_old_cwd(t_envp *envp, char *old_cwd);
void	update_cwd(t_envp *envp);
int		err_msg_cd(char *old_cwd, char *new_cwd);

int		ft_echo(t_cmd *cmd, t_envp *envp);

int		ft_env(char *arg, t_envp *envp);

int		ft_exit(t_cmd *cmd, t_sh *tofree);

int		ft_export(t_cmd *cmd, t_envp **envp);
void	print_export(t_envp *envp);
bool	is_invalid_key(char *key);
char	*get_key(char *arg);
char	*get_value(char *arg);
void	reset_export(t_envp *envp);
char	*assemble_envar(char *key, char *value);

int		ft_pwd(void);

int		ft_unset(t_cmd *cmd, t_envp **envp);

	///// EXEC /////

void	exec_handler(t_sh *sh);

	// cmd_exec
void	cmd_err_msg(char *cmd);

void	exec_commands(t_sh *sh);

int		count_commands(t_cmd *cmd);
int		last_cmd(t_arg *arg);
int		ft_fork(t_sh *sh);
void	ft_wait_all(void);

int		exit_code_handler(int error_code, int status);
int		set_exit_code(int error_code);

char	**fetch_cmd_args(t_arg *current);

char	*get_path(t_cmd *cmd, t_envp *envp);

void	save_commands(t_sh *sh);

	// envp
void	append_env_node(t_envp **env_cpy, char *env_var, t_sh *tofree);
void	set_key(t_envp **env_cpy, char *env_var);
void	set_value(t_envp **env_cpy, char *env_var);
int		count_vars(t_envp *envp);

t_envp	*save_envp(char **env, t_sh *tofree);
char	**restore_envp(t_envp *envp);

	// file
int		check_file_creation(t_arg *arg);

	// free_close
void	close_all_fds(void);
void	close_if_valid(int fd);
void	close_saved_fds(int saved_stdfd[2]);

void	*err_close_args(void);
void	err_exit_envp(t_sh *sh, char *path_to_cmd);
int		err_close_args_list(t_sh *sh, char *tofree);
int		exec_and_exit(t_cmd *cmd, t_envp **envp, t_sh *sh, int exit_code);
int		exit_handler(t_sh *sh);

int		free_sh(t_sh *sh);
void	free_arg(t_arg *arg);
void	free_cmd(t_cmd *cmd);
void	free_envp(t_envp *envp);

	// heredocs
void	create_missing_heredoc_cmd(t_arg *arg);

bool	last_cmd_is_heredoc(t_arg *arg);
bool	check_eof(char *line, char *delimiter);
void	unlink_heredoc_file(char *heredoc_file);

char	*heredoc_handler(char *delimiter, t_sh *sh);

	// redirections
void	check_valid_fds(t_sh *sh);

void	check_input_piped_cmds(int *fd, t_arg *arg, int stdfd_in);

bool	last_inf(t_arg *cmd);
void	check_inf_pipe(t_arg *to_check, t_arg **true_infile);
int		check_inf_delim(t_arg *to_check, char **heredoc_file, t_sh *sh);
void	check_inf_infile(t_arg *to_check, t_arg **true_infile);

int		set_infile(t_arg *cmd, int stdfd_in, int pipefd_in, t_sh *tofree);

int		open_outfile(t_arg *cmd, int *fd);
void	create_outfiles(t_arg *cmd);

int		count_redir_out(t_arg *cmd);
void	check_outf_pipe(t_arg *cmd, t_arg **true_outfile);
bool	check_outf_outfile(t_arg *cmd, t_arg **true_outfile);
bool	last_outf(t_arg *cmd);

int		set_outfile(t_arg *cmd, int stdfd_out, int pipefd_out);

int		ft_open(char *file, int *fd, int flag);
void	save_stdfd(int saved_stdfd[2]);
void	go_to_start_of_block(t_arg **cmd);
void	err_msg_file(char *infile);

void	redirect_io(t_cmd *cmd);
bool	redirect_io_nofork(t_sh *sh, t_cmd *cmd);
void	restore_io_nofork(t_sh *sh, t_cmd *cmd);

	// signals
void	sig_int_state(int sig);
void	sig_quit_state(int sig);
void	sigint_muted(int signal);
void	sigint_heredoc(int sig);

	///// PARSING /////

int		parse_input(char *input, t_sh *sh);

	// lexer
int		is_special_char(char c);
int		is_special_symbol(char *c);

void	lexer_v2(t_arg *head);

	//true_line
int		count_missing_spaces(char *str);
bool	missing_space_before(char *str, int i);
bool	missing_space_after(char *str, int i);
bool	is_whitespace(char c);
int		get_key_len(char *input, int i);

char	*true_line(char *str, t_sh *sh);

char	*replace_exit_code(char *input, int *i, int exit_code);
char	*find_value(char *key, t_envp *envp);
bool	is_hd_delimiter(char *str, int i);
char	*replace_var_with_value(char *input, int *i, t_envp *envp);

char	*var_expand(char *input, t_envp *envp, int exit_code, int i);

	// utils
char	**ms_split(char *s, char c);

void	print_err(char *s1, char *s2, char *s3, char *s4);

void	remove_quote(char *str);

	//valid_input
int		is_quoted(char *input, char *c);
bool	check_pipe(char *input, int i);
bool	check_redir(char *input, int i);
bool	empty_line(char *input);

bool	valid_input(char *input, t_sh *sh);

#endif