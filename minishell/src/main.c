/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwintgen <rwintgen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 16:59:56 by amalangi          #+#    #+#             */
/*   Updated: 2024/04/22 18:09:08 by rwintgen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int g_sig;

///////// TODO //////////
// Makefile no libft			=> Arthur
// make builtins
// fix ctrl+C heredoc
// valgrind (open FDs, leaks)
// fix error msg char by char
// reorganisation
// norme
/////////////////////////

/*
valgrind --trace-children=yes --track-fds=yes --leak-check=full --track-origins=yes --show-leak-kinds=all --suppressions=.vsupp ./minishell
*/

void init_sh(t_sh *sh, char **envp)
{
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

void reset_sh(t_sh *sh)
{
	free_arg(sh->arg);
	free_cmd(sh->cmd);
	sh->arg = NULL;
	sh->cmd = NULL;
}

int	main(int argc, char **argv, char **envp)
{
	t_sh	*sh;
	char	*input;

	(void) argc;
	(void) argv;
	sh = malloc(sizeof(t_sh));
	init_sh(sh, envp);
	while (true)
	{
		signal(SIGQUIT, SIG_IGN);
		signal(SIGINT, &sigint_muted);
		input = readline("minishell $> ");
		if (!input)
			break ;
		if (empty_line(input) || open_quote(input))
		{
			if (!empty_line(input))
				add_history(input);
			free(input);
			continue ;
		}
		add_history(input);
		parse_input(input, sh);
		exec_handler(sh);
		ft_wait_all();
		reset_sh(sh);
	}
	close_saved_fds(sh->saved_stdfd);
	free_sh(sh);
	return (0);
}
