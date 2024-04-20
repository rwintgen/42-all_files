/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwintgen <rwintgen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 04:28:32 by amalangi          #+#    #+#             */
/*   Updated: 2024/04/20 11:30:25 by rwintgen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	is_special_char(char c)
{
	if (c == '>' || c == '<' || c == '|')
        return (1);
    return (0);
}

int contain_special_char(char *c)
{
    int i;

    i = 0;
    while (c[i])
    {
        if (is_special_char(c[i]))
            return (1);
        i++;
    }
    return (0);
}

// int is_input(char *str) {
//     if (ft_strncmp(str, "<", 1) == 0)
//         return INFILE;
//     return 0;
// }

// int is_heredoc(char *str) {
//     if (ft_strncmp(str, "<<", 2) == 0)
//         return HEREDOC;
//     return 0;
// }

// int is_output(char *str) {
//     if (ft_strncmp(str, ">", 1) == 0)
//         return OUTFILE;
//     return 0;
// }

// int is_append(char *str) {
//     if (ft_strncmp(str, ">>", 2) == 0)
//         return APPEND;
//     return 0;
// }

// int is_pipe(char *str) {
//     if (ft_strncmp(str, "|", 1) == 0)
//         return PIPE;
//     return 0;
// }

// int is_option(char *str) {
//     if (str[0] == '-' && str[1] != '\0')
//         return OPTION;
//     return 0;
// }

// int is_cmd(char **str, int i, t_arg *data) {
//     if (i == 0 && !contain_special_char(str[i]))
//         return CMD;
//     if (i > 0 && !(ft_strncmp(str[i - 1], ">", 1)))
//         return OUTPUT;
//     if (i > 0 && (data->type == INPUT || !ft_strncmp(str[i - 1], "|", 1) || !ft_strncmp(str[i - 1], ">", 1) || !ft_strncmp(str[i - 1], ">>", 2) || !ft_strncmp(str[i - 1], "<<", 2)))
//         return CMD;
//     return 0;
// }

// //NEW LEXER 
// int lexer(char **str, int i, t_arg *data)
// {
//     int type;
//     if ((type = is_input(str[i])))
//         return type;
//     if ((type = is_heredoc(str[i])))
//         return type;
//     if ((type = is_output(str[i])))
//         return type;
//     if ((type = is_append(str[i])))
//         return type;
//     if ((type = is_pipe(str[i])))
//         return type;
//     if ((type = is_option(str[i])))
//         return type;
//     if ((type = is_cmd(str, i, data)))
//         return type;
//     return ARG;
// }