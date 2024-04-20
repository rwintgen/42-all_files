/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_handling.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deymons <deymons@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 16:11:36 by deymons           #+#    #+#             */
/*   Updated: 2024/04/18 14:12:19 by deymons          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int is_not_found_cmd(char *str_command, t_envp *envp)
{
	if (get_var(str_command, envp))
		return (1);
	return (0);
}

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
	ft_putstr_fd("\n", 1); //TODO check si le \n est sur la sortie 1 ou 2
}

void	sig_quit_state(int sig)
{
	(void)sig;
	g_sig = 131;
	ft_putstr_fd("Quit (core dumped)\n", 2);
}

void	sigint_muted(int signal)
{
	(void)signal;
	rl_replace_line("", 1);
	ft_putstr_fd("\n", 1);
	rl_on_new_line();
	rl_redisplay();
	g_sig = SIGINT;
}