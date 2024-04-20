/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prep_for_exec.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwintgen <rwintgen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 12:31:29 by deymons           #+#    #+#             */
/*   Updated: 2024/04/20 13:46:33 by rwintgen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

// fetch the command name and its arguments from the comand line linked list
char	**fetch_cmd_args(t_arg *cmd)
{
	t_arg	*tmp;
	char	**result;
	int		cmd_argc;
	int		i;

	tmp = cmd;
	cmd_argc = 1;
	cmd = cmd->next;
	if (!ft_strncmp(tmp->str_command, "heredoc", 7))
	{
		result = add_delimiter(tmp);
		if (result == NULL)
			return (NULL);
		return (result);
	}
	while (cmd && cmd->type != CMD && cmd->type != PIPE)
	{
		if (cmd->type == ARG || cmd->type == OPTION)
			cmd_argc++;
		cmd = cmd->next;
	}
	result = malloc(sizeof(char *) * (cmd_argc + 1));
	if (!result)
	{
		ft_putstr_fd("minishell: malloc error\n", STDERR_FILENO);
		return (NULL);
	}
	cmd = tmp;
	i = 0;
	while (i < cmd_argc)
	{
		result[i] = ft_strdup(cmd->str_command);
		cmd = cmd->next;
		i++;
	}
	result[cmd_argc] = NULL;
	return (result);
}

// creates a new t_cmd node
t_cmd*	create_node(char** cmd_and_args, int fd[2], bool skip) 
{
	t_cmd* new_node;

	new_node = malloc(sizeof(t_cmd));
	new_node->is_builtin = false;
	new_node->skip_cmd = skip;
	if (is_builtin(cmd_and_args[0]))
		new_node->is_builtin = true;
	new_node->cmd_and_args = cmd_and_args;
	new_node->input_fd = fd[0];
	new_node->output_fd = fd[1];
	new_node->prev = NULL;
	new_node->next = NULL;
	return (new_node);
}

// adds a new t_cmd node to the linked list
void	add_to_list(t_sh *sh, char **cmd_and_args, int fd[2], bool skip)
{
	t_cmd	*new_node;
	t_cmd	*current;

	new_node = create_node(cmd_and_args, fd, skip);
	if (!(sh->cmd))
		sh->cmd = new_node;
	else
	{
		current = sh->cmd;
		while (current->next)
			current = current->next;
		current->next = new_node;
		new_node->prev = current;
	}
}

void	reset_pipefd(int pipefd[2])
{
	pipefd[0] = -1;
	pipefd[1] = -1;
}

void free_t_arg(t_arg *input)
{
	t_arg *tmp;

	while (input)
	{
		tmp = input;
		input = input->next;
		free(tmp->str_command);
		free(tmp);
	}
}

// converts t_arg to t_cmd linked list
void	t_arg_to_t_cmd(t_sh *sh)
{
	char		**cmd_and_args;
	int			fd[2];
	int			prev_fd_in;
	bool		skip;

	while (sh->arg)
	{
		skip = false;
		if (sh->arg->type == DELIM && missing_heredoc_cmd(sh->arg))
			create_heredoc_cmd(sh->arg);
		if (sh->arg->type == CMD)
		{
			prev_fd_in = sh->pipefd[0];
			reset_pipefd(sh->pipefd);
			if (!(last_cmd(sh->arg)))
			{
				if (pipe(sh->pipefd) == -1)
				{
					skip = true;
					ft_putstr_fd("minishell: pipe error\n", STDERR_FILENO);
					return ;
				}
			}
			cmd_and_args = fetch_cmd_args(sh->arg);
			fd[0] = set_infile(sh->arg, sh->saved_stdfd[0], prev_fd_in);
			fd[1] = set_outfile(sh->arg, sh->saved_stdfd[1], sh->pipefd[1]);
			add_to_list(sh, cmd_and_args, fd, skip);
			ft_memset(fd, -1, sizeof(int) * 2);
		}
		sh->arg = sh->arg->next;
	}
}