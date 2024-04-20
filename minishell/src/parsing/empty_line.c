/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   empty_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deymons <deymons@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 17:57:51 by amalangi          #+#    #+#             */
/*   Updated: 2024/04/07 21:12:10 by deymons          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int		empty_line(char *input)
{
    int i;
    
    i = 0;
    while (input[i])
    {
        if (input[i] != ' ' && input[i] != '\t' && input[i] != '\n' && input[i] != '\v' && input[i] != '\f' && input[i] != '\r')
            return (false);
        i++;
    }
    return (true);
}