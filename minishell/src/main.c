/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwintgen <rwintgen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 16:59:56 by amalangi          #+#    #+#             */
/*   Updated: 2024/05/02 12:06:05 by rwintgen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int g_sig;

///////// TODO //////////
// make builtins
//// cd unset HOME segfault
//// env no option nor args
//// sort export no arg
//// fix exit
// fix ctrl+C heredoc
// valgrind (open FDs, leaks)
// fix error msg char by char
// reorganisation
// norme
/////////////////////////

/*
valgrind --trace-children=yes --track-fds=yes --leak-check=full --track-origins=yes --show-leak-kinds=all --suppressions=.vsupp ./minishell
*/

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
	sh->pipefd[1] = -1;
	sh->exit_code = 0;
	sh->envp = save_envp(envp);
}

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
