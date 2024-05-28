/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwintgen <rwintgen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 15:14:32 by rwintgen          #+#    #+#             */
/*   Updated: 2024/05/28 15:15:03 by rwintgen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static bool	over_int_max(char *str, int i);
static bool	under_int_min(char *str, int i);
static bool	is_full_digit(char *str);
static int	err_msg_exit(char *msg, t_sh *tofree);

int	ft_exit(t_cmd *cmd, t_sh *tofree)
{
	int	exit_code;

	exit_code = tofree->exit_code;
	if (!cmd->cmd_and_args[1])
		exit(exit_handler(tofree));
	if (!is_full_digit(cmd->cmd_and_args[1]))
		exit(err_msg_exit(E_EXIT_NUM, tofree));
	if (cmd->cmd_and_args[2])
		return (err_msg_exit(E_EXIT_ARGC, tofree));
	else
		exit_code = ft_atoi(cmd->cmd_and_args[1]);
	free_sh(tofree);
	write(3, "exit\n", 5);
	close_all_fds();
	exit(exit_code);
}

static bool	over_int_max(char *str, int i)
{
	if (ft_strlen(str + i) > 19)
		return (true);
	if (ft_strlen(str + i) == 19 && ft_strncmp(str + i, INT_64_MAX, 19) > 0)
		return (true);
	return (false);
}

static bool	under_int_min(char *str, int i)
{
	if (ft_strlen(str + i) > 19)
		return (true);
	if (ft_strlen(str + i) == 19 && ft_strncmp(str + i, INT_64_MIN, 19) > 0)
		return (true);
	return (false);
}

static bool	is_full_digit(char *str)
{
	int		i;
	bool	minus;

	i = 0;
	minus = false;
	while (str[i] && str[i] == ' ')
		i++;
	if (str[i] && str[i] == '+')
		i++;
	else if (str[i] && str[i] == '-')
	{
		i++;
		minus = true;
	}
	while (str[i] && str[i] == '0')
		i++;
	if ((minus && under_int_min(str, i)) || (!minus && over_int_max(str, i)))
		return (false);
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (false);
		i++;
	}
	return (true);
}

static int	err_msg_exit(char *msg, t_sh *tofree)
{
	if (!ft_strcmp(E_EXIT_ARGC, msg))
	{
		ft_putendl_fd(E_EXIT_ARGC, STDERR_FILENO);
		return (1);
	}
	else if (!ft_strcmp(E_EXIT_NUM, msg))
	{
		ft_putendl_fd(E_EXIT_NUM, STDERR_FILENO);
		free_sh(tofree);
		close_all_fds();
		return (2);
	}
	return (SUCCESS);
}
