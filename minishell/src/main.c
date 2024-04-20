/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwintgen <rwintgen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 16:59:56 by amalangi          #+#    #+#             */
/*   Updated: 2024/04/20 14:23:54 by rwintgen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int g_sig;

///////// TODO //////////
// fix quotes					=> Arthur
// fix varaible expansion		=> Arthur
// Makefile no libft			=> Arthur
// modif exec for builtins
// fix ctrl+C heredoc
// make builtins
// valgrind (open FDs, leaks)
// fix error msg char by char
// reorganisation
// norme
/////////////////////////

/*
valgrind --trace-children=yes --track-fds=yes --leak-check=full  --track-origins=yes --show-leak-kinds=all --suppressions=.vsupp ./minishell
*/

void init_sh(t_sh *sh, char **envp)
{
	sh->arg = malloc(sizeof(t_arg));
	sh->arg = NULL;
	sh->cmd = malloc(sizeof(t_cmd));
	sh->cmd = NULL;
	sh->envp = malloc(sizeof(t_envp));
	sh->envp = NULL;
	sh->saved_stdfd[0] = dup(STDIN_FILENO);
	sh->saved_stdfd[1] = dup(STDIN_FILENO);
	sh->pipefd[0] = -1;
	sh->pipefd[1] = -1;
	sh->exit_code = 0;
	sh->envp = copy_envp(envp);
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
		sh->arg = NULL;
		ft_wait_all();
	}
	free_sh(sh);
	return (0);
}
