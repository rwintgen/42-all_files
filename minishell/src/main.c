/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwintgen <rwintgen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 16:59:56 by amalangi          #+#    #+#             */
/*   Updated: 2024/05/15 12:34:06 by rwintgen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	g_sig;

///////// TODO //////////
// file name with spaces 						??
// fix ctrl+C heredoc							??
//// ctrl+C heredoc -> outfile created
//// ctrl+C heredoc -> next commands executed
// fix error msg char by char					??
// valgrind (open FDs, leaks)					OK-ish
// norme										OK-ish
// fix export segfaults							TODO
/////////////////////////

/*
clear && valgrind --trace-children=yes --track-fds=yes --leak-check=full 
--track-origins=yes --show-leak-kinds=all --suppressions=.vsupp ./minishell
*/

static void	init_sh(t_sh *sh, char **envp, int argc, char **argv);
static void	reset_sh(t_sh *sh);

int	main(int argc, char **argv, char **envp)
{
	t_sh	*sh;
	char	*input;

	sh = malloc(sizeof(t_sh));
	if (!sh)
		return (EXIT_FAILURE);
	init_sh(sh, envp, argc, argv);
	while (true)
	{
		signal(SIGQUIT, SIG_IGN);
		signal(SIGINT, sigint_muted);
		input = readline("minishell $> ");
		if (!input)
			break ;
		if (!valid_input(input, sh) || parse_input(input, sh) == ERROR)
			continue ;
		exec_handler(sh);
		ft_wait_all();
		reset_sh(sh);
	}
	close_all_fds();
	free_sh(sh);
	write (STDOUT_FILENO, "exit\n", 5);
	return (EXIT_SUCCESS);
}

// initializes sh struct at program launch
static void	init_sh(t_sh *sh, char **envp, int argc, char **argv)
{
	(void) argc;
	(void) argv;
	sh->arg = NULL;
	sh->cmd = NULL;
	sh->envp = NULL;
	sh->saved_stdfd[0] = dup(STDIN_FILENO);
	sh->saved_stdfd[1] = dup(STDOUT_FILENO);
	sh->pipefd[0] = -1;
	sh->exit_code = 0;
	sh->envp = save_envp(envp);
}

// resets sh structure elements after each propmpt
static void	reset_sh(t_sh *sh)
{
	free_arg(sh->arg);
	free_cmd(sh->cmd);
	sh->arg = NULL;
	sh->cmd = NULL;
	sh->pipefd[0] = -1;
	sh->pipefd[1] = -1;
}
