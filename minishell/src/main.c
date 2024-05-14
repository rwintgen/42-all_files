/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwintgen <rwintgen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 16:59:56 by amalangi          #+#    #+#             */
/*   Updated: 2024/05/14 13:01:23 by rwintgen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	g_sig;

///////// TODO //////////
// file name with spaces 						??
// fix ctrl+C heredoc -> outfile created		??
// fix error msg char by char					??
// valgrind (open FDs, leaks)					OK-ish
// norme										OK-ish
// exit does not print "exit"					TODO
// fix export segfaults							TODO
// reorganisation
//// make functions static						TODO
//// put functions in the right order			TODO
//// replace 0 and 1 with SUCCES/FAILURE		TODO
//// redo .h file								TODO
/////////////////////////

/*
clear && valgrind --trace-children=yes --track-fds=yes --leak-check=full --track-origins=yes --show-leak-kinds=all --suppressions=.vsupp ./minishell
*/

// initializes sh struct at program launch
void	init_sh(t_sh *sh, char **envp, int argc, char **argv)
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
void	reset_sh(t_sh *sh)
{
	free_arg(sh->arg);
	free_cmd(sh->cmd);
	sh->arg = NULL;
	sh->cmd = NULL;
	sh->pipefd[0] = -1;
	sh->pipefd[1] = -1;
}

int	main(int argc, char **argv, char **envp)
{
	t_sh	*sh;
	char	*input;

	sh = malloc(sizeof(t_sh));
	if (!sh)
		return (1);
	init_sh(sh, envp, argc, argv);
	while (true)
	{
		signal(SIGQUIT, SIG_IGN);
		signal(SIGINT, &sigint_muted);
		input = readline("minishell $> ");
		if (!input)
			break ;
		if (!valid_input(input, sh) || parse_input(input, sh) == -1)
			continue ;
		exec_handler(sh);
		ft_wait_all();
		reset_sh(sh);
	}
	close_all_fds();
	free_sh(sh);
	write (1, "exit\n", 5);
	return (0);
}
