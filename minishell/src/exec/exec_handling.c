/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_handling.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwintgen <rwintgen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 17:59:02 by deymons           #+#    #+#             */
/*   Updated: 2024/04/20 11:55:44 by rwintgen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

// waits for all children processes to finish
void	ft_wait_all(void)
{
	int	status;

	while (wait(&status) > 0)
	{
	}
}

// handles command execution and FDs
void	exec_handler(t_sh *sh)
{
	signal(SIGQUIT, &sig_quit_state);
	signal(SIGINT, &sig_int_state);
	t_arg_to_t_cmd(sh);
	print_t_cmd_struct(sh->cmd);
	exec_commands(sh);
	printf("\nlast cmd exit code: %d\n\n=================\n\n", sh->exit_code);
}
