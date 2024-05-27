/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_handling.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwintgen <rwintgen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 17:59:02 by deymons           #+#    #+#             */
/*   Updated: 2024/05/27 13:55:42 by rwintgen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	remove_all_quotes(t_sh *sh);

// handles command execution and i.o redirection
void	exec_handler(t_sh *sh)
{
	g_sig = 0;
	signal(SIGQUIT, sig_quit_state);
	signal(SIGINT, sig_int_state);
	remove_all_quotes(sh); // NO MALLOC
	save_commands(sh);
	// print_t_cmd_struct(sh->cmd); // DEBUG
	if (check_file_creation(sh->arg) == ERROR)
		sh->exit_code = 1;
	if (count_commands(sh->cmd) == 0)
		return ;
	exec_commands(sh);
}

// removes all quotes from the command line
static void	remove_all_quotes(t_sh *sh)
{
	t_arg	*tmp;

	tmp = sh->arg;
	while (tmp)
	{
		remove_quote(tmp->str_command);
		tmp = tmp->next;
	}
}
