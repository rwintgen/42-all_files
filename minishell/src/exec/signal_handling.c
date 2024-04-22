/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_handling.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwintgen <rwintgen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 16:11:36 by deymons           #+#    #+#             */
/*   Updated: 2024/04/22 17:19:35 by rwintgen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	set_exit_status(int sig, t_envp **envp)
{
	while ((*envp))
	{
		if ((*envp)->key && !ft_strncmp((*envp)->key, "?", 1))
		{
			free((*envp)->envar);
			(*envp)->envar = ft_strjoin("?", "=");
			(*envp)->envar = ft_strjoin((*envp)->envar, ft_itoa(sig));
			(*envp)->value = ft_itoa(sig);
			break ;
		}
		(*envp) = (*envp)->next;
	}
}

void	sig_int_state(int sig)
{
	(void)sig;
	g_sig = 130;
	ft_putstr_fd("\n", STDERR_FILENO); //TODO check si le \n est sur la sortie 1 ou 2
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
