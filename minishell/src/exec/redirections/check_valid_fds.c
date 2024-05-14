/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_valid_fds.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwintgen <rwintgen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 19:15:27 by rwintgen          #+#    #+#             */
/*   Updated: 2024/05/14 13:45:16 by rwintgen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	check_grep(int fd, t_sh *tofree);
static void	check_cat_wc(int fd, t_sh *tofree);

// exits if one of cmd's FD is invalid
void	check_valid_fds(t_sh *sh)
{
	check_grep(sh->cmd->input_fd, sh);
	check_cat_wc(sh->cmd->input_fd, sh);
	if (sh->cmd->input_fd < 0)
	{
		close_all_fds();
		errno = 0;
		exit(free_sh(sh));
	}
	else if (sh->cmd->output_fd < 0)
	{
		close_all_fds();
		errno = 0;
		exit(free_sh(sh));
	}
}

// exits with right exit code if grep waits for input
static void	check_grep(int fd, t_sh *tofree)
{
	if (fd == -3)
	{
		close_all_fds();
		errno = 0;
		free_sh(tofree);
		exit(1);
	}
}

// exits with right exit code if cat or wc waits for input
static void	check_cat_wc(int fd, t_sh *tofree)
{
	if (fd == -2)
	{
		close_all_fds();
		errno = 0;
		free_sh(tofree);
		exit(0);
	}
}
