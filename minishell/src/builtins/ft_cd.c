/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwintgen <rwintgen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 02:42:25 by amalangi          #+#    #+#             */
/*   Updated: 2024/05/30 17:02:27 by rwintgen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_cd(t_cmd *cmd, t_envp *envp)
{
	char	*new_cwd;
	char	*old_cwd;

	if (cmd->cmd_and_args[1] && cmd->cmd_and_args[2])
	{
		print_err(E_CD_ARGC, NULL, NULL, NULL);
		return (FAILURE);
	}
	if (!cmd->cmd_and_args[1] || !ft_strcmp(cmd->cmd_and_args[1], "~"))
	{
		new_cwd = get_home(envp);
		if (!new_cwd)
			return (FAILURE);
	}
	else
		new_cwd = cmd->cmd_and_args[1];
	old_cwd = get_cwd();
	if (old_cwd == NULL)
		return (FAILURE);
	if (chdir(new_cwd) == -1)
		return (err_msg_cd(old_cwd, new_cwd));
	update_old_cwd(envp, old_cwd);
	update_cwd(envp);
	free(old_cwd);
	return (SUCCESS);
}
