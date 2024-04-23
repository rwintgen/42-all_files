/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_handling.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwintgen <rwintgen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 17:59:02 by deymons           #+#    #+#             */
/*   Updated: 2024/04/23 12:37:09 by rwintgen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

// handles command execution and i.o redirection
void	exec_handler(t_sh *sh)
{
	signal(SIGQUIT, &sig_quit_state);
	signal(SIGINT, &sig_int_state);
	save_commands(sh);
	print_t_cmd_struct(sh->cmd);
	exec_commands(sh);
	printf("\nlast cmd exit code: %d\n\n=================\n\n", sh->exit_code);
}
