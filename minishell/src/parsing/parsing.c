/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwintgen <rwintgen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 16:28:53 by amalangi          #+#    #+#             */
/*   Updated: 2024/04/20 13:46:28 by rwintgen         ###   ########.fr       */
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
    while (head->prev)
        head = head->prev;
    set_spec(head);
    set_file(head);
    set_cmd(head);
    set_arg(head);

}

int fill_t_arg_struct(t_sh *sh, char *input)
{
    char **tmp;
    t_arg *ptr;
    t_arg *new;
    int i;

    i = 0;
    tmp = ft_split(input, ' ');
    ptr = NULL;
    while (tmp[i])
    {
        new = malloc(sizeof(t_arg));
        if (!new)
        {
            ft_putstr_fd("minishell: malloc error\n", STDERR_FILENO);
            return (-1);
        }
        new->str_command = ft_strdup(tmp[i]);
        new->prev = NULL;
        new->next = NULL;
        new->type = -1;

        if (sh->arg == NULL)
        {
            sh->arg = new;
            ptr = sh->arg;
        }
        else
        {
            ptr->next = new;
            new->prev = ptr;
            ptr = ptr->next;
        }
        i++;
    }
    lexer_v2(ptr);
    free_tab(tmp);
    return (0);
}

void	parse_input(char *input, t_sh *sh)
{
	printf("\n\nPARSING\n\n");
	input = true_line(input, sh);
	fill_t_arg_struct(sh, input);
	free(input);
	print_t_arg_struct(sh->arg);
}