/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_handling.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwintgen <rwintgen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 17:59:02 by deymons           #+#    #+#             */
/*   Updated: 2024/04/25 15:57:44 by rwintgen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// handles command execution and i.o redirection
void	exec_handler(t_sh *sh)
{
	signal(SIGQUIT, &sig_quit_state);
	signal(SIGINT, &sig_int_state);
	save_commands(sh);
	// print_t_cmd_struct(sh->cmd); // DEBUG
	exec_commands(sh);
	// printf("last cmd exit code: %d\n\n", sh->exit_code); // DEBUG
}
