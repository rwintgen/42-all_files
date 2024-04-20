/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwintgen <rwintgen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 16:28:53 by amalangi          #+#    #+#             */
/*   Updated: 2024/04/20 15:28:41 by rwintgen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void free_tab(char **tab)
{
    int i;

    i = 0;
    while (tab[i])
    {
        free(tab[i]);
        i++;
    }
    free(tab);
}

void    set_spec(t_arg *elem)
{
    while (elem)
    {
        if (ft_strncmp(elem->str_command, "<<", 2) == 0)
            elem->type = HEREDOC;
        else if (ft_strncmp(elem->str_command, "<", 1) == 0)
            elem->type = INPUT;
        else if (ft_strncmp(elem->str_command, ">>", 2) == 0)
            elem->type = APPEND;
        else if (ft_strncmp(elem->str_command, ">", 1) == 0)
            elem->type = OUTPUT;
        else if (ft_strncmp(elem->str_command, "|", 1) == 0)
            elem->type = PIPE;
        elem = elem->next;
    }
}

void    set_file(t_arg *elem)
{
    while (elem)
    {
        if (elem->prev && elem->prev->type == INPUT)
            elem->type = INFILE;
        else if (elem->prev && elem->prev->type == OUTPUT)
            elem->type = OUTFILE;
        else if (elem->prev && elem->prev->type == APPEND)
            elem->type = OUTFILE;
        else if (elem->prev && elem->prev->type == HEREDOC)
            elem->type = DELIM;
        elem = elem->next;
    }
}

void    set_cmd(t_arg *elem)
{
    while (elem->next)
        elem = elem->next;
    while (elem)
    {
        if (elem->type == -1 && (!elem->prev || elem->prev->type >= 0))
            elem->type = CMD;
        elem = elem->prev;
    }
}

void    set_arg(t_arg *elem)
{
    while (elem)
    {
        if (elem->type == -1 && elem->str_command[0] == '-')
            elem->type = OPTION;
        else if (elem->type == -1 && elem->str_command[0] != '-')
            elem->type = ARG;
        elem = elem->next;
    }
}

void    lexer_v2(t_arg *head)
{
    set_spec(head);
    set_file(head);
    set_cmd(head);
    set_arg(head);
}

void	append_arg_node(t_arg **arg_cpy, char *arg)
{
	t_arg *new_node;
	t_arg *tmp;
	
	new_node = malloc(sizeof(t_arg));
	if (!new_node)
	{
		ft_putstr_fd("minishell: malloc error\n", STDERR_FILENO);
		// free
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


t_arg	*copy_args(char *input)
{
	t_arg	*arg_cpy;
    char    **args;
	int		i;

    args = ft_split(input, ' ');
	arg_cpy = NULL;
	i = 0;
	while (args[i])
	{
		append_arg_node(&arg_cpy, args[i]);
		i++;
	}
    lexer_v2(arg_cpy);
    ft_free_char_tab(args);
	return (arg_cpy);
}

void	parse_input(char *input, t_sh *sh)
{
	printf("\n\nPARSING\n\n");
	input = true_line(input, sh);
	sh->arg = copy_args(input);
	free(input);
	print_t_arg_struct(sh->arg);
}