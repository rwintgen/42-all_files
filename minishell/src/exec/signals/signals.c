/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwintgen <rwintgen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 16:11:36 by deymons           #+#    #+#             */
/*   Updated: 2024/05/24 14:48:38 by rwintgen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	sig_int_state(int sig)
{
	(void)sig;
	g_sig = 130;
	ft_putstr_fd("\n", STDERR_FILENO);
}

void	sig_quit_state(int sig)
{
	(void)sig;
	g_sig = 131;
	ft_putstr_fd("Quit (core dumped)\n", STDERR_FILENO);
}

void	sigint_muted(int signal)
{
	(void)signal;
	rl_replace_line("", STDOUT_FILENO);
	ft_putstr_fd("\n", STDOUT_FILENO);
	rl_on_new_line();
	rl_redisplay();
	g_sig = SIGINT;
}

void	sigint_heredoc(int sig)
{
	(void)sig;
	g_sig = SIGINT;
	close(STDIN_FILENO);
}
