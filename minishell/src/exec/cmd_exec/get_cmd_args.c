/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cmd_args.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwintgen <rwintgen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 11:46:24 by rwintgen          #+#    #+#             */
/*   Updated: 2024/04/23 13:07:16 by rwintgen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

// fetch the command name and its arguments from the command line
char	**fetch_cmd_args(t_arg *current)
{
	t_arg	*cmd;
	char	**result;
	int		cmd_argc;

	cmd = current;
	cmd_argc = 1;
	current = current->next;
	if (!ft_strncmp(cmd->str_command, "heredoc", 7))
	{
		result = add_delimiter(cmd);
		if (result == NULL)
			return (NULL);
		return (result);
	}
	increment_cmd_argc(&cmd_argc, current);
	result = malloc(sizeof(char *) * (cmd_argc + 1));
	if (!result)
	{
		ft_putstr_fd("minishell: malloc error\n", STDERR_FILENO);
		return (NULL);
	}
	current = cmd;
	fill_arg_arr(cmd_argc, &result, current);
	return (result);
}

// increment the command argument count for malloc
void	increment_cmd_argc(int *cmd_argc, t_arg *current)
{
	while (current && current->type != CMD && current->type != PIPE)
	{
		if (current->type == ARG || current->type == OPTION)
			(*cmd_argc)++;
		current = current->next;
	}
}

// fills the argument array with the command name and its arguments
void	fill_arg_arr(int cmd_argc, char ***result, t_arg *cmd)
{
	int	i;

	i = 0;
	while (i < cmd_argc)
	{
		(*result)[i] = ft_strdup(cmd->str_command);
		cmd = cmd->next;
		i++;
	}
	(*result)[cmd_argc] = NULL;
}
