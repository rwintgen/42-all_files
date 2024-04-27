/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_handling.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwintgen <rwintgen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 17:59:02 by deymons           #+#    #+#             */
/*   Updated: 2024/04/27 17:34:42 by rwintgen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// handles command execution and i.o redirection
void	exec_handler(t_sh *sh)
{
	signal(SIGQUIT, &sig_quit_state);
	signal(SIGINT, &sig_int_state);
	remove_all_quotes(sh);
	save_commands(sh);
	// print_t_cmd_struct(sh->cmd); // DEBUG
	if (check_file_creation(sh->arg) == -1)
		sh->exit_code = 1;
	if (count_commands(sh->cmd) == 0)
		return ;
	exec_commands(sh);
	// printf("last cmd exit code: %d\n\n", sh->exit_code); // DEBUG
}

void	remove_all_quotes(t_sh *sh)
{
	t_arg	*tmp;

	tmp = sh->arg;
	while (tmp)
	{
		remove_quote(tmp->str_command);
		tmp = tmp->next;
	}
}
