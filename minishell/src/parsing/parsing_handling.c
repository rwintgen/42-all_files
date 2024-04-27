/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_handling.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwintgen <rwintgen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 16:28:53 by amalangi          #+#    #+#             */
/*   Updated: 2024/04/27 17:34:47 by rwintgen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// handles input parsing functions
int	parse_input(char *input, t_sh *sh)
{
	input = true_line(input, sh);
	if (!*input)
	{
		free(input);
		return (-1);
	}
	sh->arg = copy_args(input, sh);
	free(input);
	// print_t_arg_struct(sh->arg); // DEBUG
	return (0);
}

// saves command line args into t_arg linked list
t_arg	*copy_args(char *input, t_sh *sh)
{
	t_arg	*arg_cpy;
	char	**args;
	int		i;

	args = ms_split(input, ' ');
	arg_cpy = NULL;
	i = 0;
	while (args[i])
	{

		append_arg_node(&arg_cpy, args[i], sh);
		i++;
	}
	lexer_v2(arg_cpy);
	ft_free_char_tab(args);
	return (arg_cpy);
}

// appends a new node to the t_arg linked list
void	append_arg_node(t_arg **arg_cpy, char *arg, t_sh *sh)
{
	t_arg	*new_node;
	t_arg	*tmp;

	new_node = malloc(sizeof(t_arg));
	if (!new_node)
	{
		ft_putendl_fd(E_MALLOC, STDERR_FILENO);
		free_sh(sh);
		close_all_fds();
		exit(1);
	}
	new_node->str_command = ft_strdup(arg);
	new_node->type = -1;
	new_node->next = NULL;
	new_node->prev = NULL;
	if (*arg_cpy == NULL)
		*arg_cpy = new_node;
	else
	{
		tmp = *arg_cpy;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new_node;
		new_node->prev = tmp;
	}
}
