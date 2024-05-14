/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cmd_args.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwintgen <rwintgen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 11:46:24 by rwintgen          #+#    #+#             */
/*   Updated: 2024/05/14 13:39:37 by rwintgen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	increment_cmd_argc(int *cmd_argc, t_arg *current);
static void	fill_arg_arr(int cmd_argc, char ***result, t_arg *cmd);
static char	**add_delimiter(t_arg *cmd);

// fetch the command name and its arguments from the command line
char	**fetch_cmd_args(t_arg *current)
{
	t_arg	*cmd;
	char	**result;
	int		cmd_argc;

	cmd = current;
	cmd_argc = 1;
	current = current->next;
	if (!ft_strcmp(cmd->str_command, "heredoc"))
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
		ft_putendl_fd(E_MALLOC, STDERR_FILENO);
		return (NULL);
	}
	current = cmd;
	fill_arg_arr(cmd_argc, &result, current);
	return (result);
}

// increment the command argument count for malloc
static void	increment_cmd_argc(int *cmd_argc, t_arg *current)
{
	while (current && current->type != CMD && current->type != PIPE)
	{
		if (current->type == ARG || current->type == OPTION)
			(*cmd_argc)++;
		current = current->next;
	}
}

// fills the argument array with the command name and its arguments
static void	fill_arg_arr(int cmd_argc, char ***result, t_arg *cmd)
{
	int	i;

	i = 0;
	while (i < cmd_argc && cmd && cmd->type != PIPE)
	{
		if (cmd->type == CMD || cmd->type == ARG || cmd->type == OPTION)
		{
			(*result)[i] = ft_strdup(cmd->str_command);
			i++;
		}
		cmd = cmd->next;
	}
	(*result)[cmd_argc] = NULL;
}

// adds heredoc delimiter to the command
static char	**add_delimiter(t_arg *cmd)
{
	char	**result;

	result = malloc(sizeof(char *) * 3);
	if (!result)
	{
		ft_putendl_fd(E_MALLOC, STDERR_FILENO);
		return (NULL);
	}
	result[0] = ft_strdup("chibron");
	result[1] = ft_strdup(cmd->prev->str_command);
	result[2] = NULL;
	return (result);
}
