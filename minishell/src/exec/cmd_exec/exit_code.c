/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_code.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwintgen <rwintgen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 11:42:31 by rwintgen          #+#    #+#             */
/*   Updated: 2024/04/25 15:57:38 by rwintgen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	exit_code_handler(int error_code, int status)
{
	if (WIFEXITED(status))
		return (WEXITSTATUS(status));
	else if (WIFSIGNALED(status))
		return (128 + WTERMSIG(status));
	else if (WIFSTOPPED(status))
		return (128 + WSTOPSIG(status));
	else if (WIFCONTINUED(status))
		return (0);
	else if (error_code == ENOENT)
		return (127);
	else if (error_code == EACCES)
		return (126);
	else
		return (1);
}

int	set_exit_code(int error_code)
{
	if (error_code == ENOENT)
		return (127);
	else if (error_code == EACCES)
		return (126);
	else
		return (1);
}
