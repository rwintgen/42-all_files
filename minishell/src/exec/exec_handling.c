/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_handling.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwintgen <rwintgen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 17:59:02 by deymons           #+#    #+#             */
/*   Updated: 2024/05/30 17:50:20 by rwintgen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	remove_all_quotes(t_sh *sh);

// handles command execution and i.o redirection
void	exec_handler(t_sh *sh)
{
	signal(SIGQUIT, sig_quit_state);
	signal(SIGINT, sig_int_state);
	remove_all_quotes(sh);
	save_commands(sh);
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
