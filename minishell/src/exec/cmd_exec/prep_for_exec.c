/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prep_for_exec.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwintgen <rwintgen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 12:31:29 by deymons           #+#    #+#             */
/*   Updated: 2024/05/13 18:38:36 by rwintgen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// saves the commands in a t_cmd linked list
void	save_commands(t_sh *sh)
{
	char		**cmd_and_args;
	int			fd[2];
	int			prev_fd_in;
	t_arg		*tmp;

	tmp = sh->arg;
	create_missing_heredoc_cmd(tmp);
	while (tmp)
	{
		if (tmp->type == CMD)
		{
			prev_fd_in = sh->pipefd[0];
			reset_pipefd(sh->pipefd);
			pipe_if_needed(tmp, sh);
			fd[0] = set_infile(tmp, sh->saved_stdfd[0], prev_fd_in, sh);
			fd[1] = set_outfile(tmp, sh->saved_stdfd[1], sh->pipefd[1]);
			cmd_and_args = fetch_cmd_args(tmp);
			if (!cmd_and_args)
				continue ;
			add_to_list(sh, cmd_and_args, fd);
		}
		tmp = tmp->next;
	}
}

// adds a new t_cmd node to the linked list
void	add_to_list(t_sh *sh, char **cmd_and_args, int fd[2])
{
	t_cmd	*new_node;
	t_cmd	*current;

	new_node = create_node(cmd_and_args, fd);
	if (!new_node)
		return ;
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

// creates a new t_cmd node
t_cmd	*create_node(char **cmd_and_args, int fd[2])
{
	t_cmd	*new_node;

	new_node = malloc(sizeof(t_cmd));
	if (!new_node)
	{
		ft_putendl_fd(E_MALLOC, STDERR_FILENO);
		return (NULL);
	}
	new_node->is_builtin = false;
	if (is_builtin(cmd_and_args[0]))
		new_node->is_builtin = true;
	new_node->cmd_and_args = cmd_and_args;
	new_node->input_fd = fd[0];
	new_node->output_fd = fd[1];
	new_node->prev = NULL;
	new_node->next = NULL;
	return (new_node);
}

// checks if a pipe is needed and handles pipe error
void	pipe_if_needed(t_arg *tmp, t_sh *sh)
{
	if (!(last_cmd(tmp)))
	{
		if (pipe(sh->pipefd) == -1)
		{
			ft_putendl_fd(E_PIPE, STDERR_FILENO);
			return ;
		}
	}
}

// resets the pipe file descriptors to -1
void	reset_pipefd(int pipefd[2])
{
	pipefd[0] = -1;
	pipefd[1] = -1;
}
