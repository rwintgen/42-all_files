/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_handling.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwintgen <rwintgen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 16:28:53 by amalangi          #+#    #+#             */
/*   Updated: 2024/05/30 17:52:18 by rwintgen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static t_arg	*copy_args(char *input, t_sh *sh);
static int		append_arg_node(t_arg **arg_cpy, char *arg, t_sh *sh);

// handles input parsing functions
int	parse_input(char *input, t_sh *sh)
{
	input = true_line(input, sh);
	if (!input || !*input)
	{
		free(input);
		return (ERROR);
	}
	sh->arg = copy_args(input, sh);
	free(input);
	return (SUCCESS);
}

// saves command line args into t_arg linked list
static t_arg	*copy_args(char *input, t_sh *sh)
{
	t_arg	*arg_cpy;
	char	**args;
	int		i;

	args = ms_split(input, ' ');
	if (!args)
	{
		err_close_args_list(sh, input);
		exit(EXIT_FAILURE);
	}
	arg_cpy = NULL;
	i = 0;
	while (args[i])
	{
		if (append_arg_node(&arg_cpy, args[i], sh) == ERROR)
		{
			ft_free_char_tab(args);
			free(input);
			exit(EXIT_FAILURE);
		}
		i++;
	}
	lexer_v2(arg_cpy);
	ft_free_char_tab(args);
	return (arg_cpy);
}

// appends a new node to the t_arg linked list
static int	append_arg_node(t_arg **arg_cpy, char *arg, t_sh *sh)
{
	t_arg	*new_node;
	t_arg	*tmp;

	new_node = malloc(sizeof(t_arg));
	if (!new_node)
		return (err_close_args_list(sh, NULL));
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
	return (SUCCESS);
}
