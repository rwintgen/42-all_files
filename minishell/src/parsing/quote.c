/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quote.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deymons <deymons@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 14:28:16 by amalangi          #+#    #+#             */
/*   Updated: 2024/04/07 21:12:58 by deymons          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int		open_quote(char *input)
{
    int	i;
    int	single_quote;
    int double_quote;
    
    i = 0;
    single_quote = 0;
    double_quote = 0;
    while (input[i])
    {
        if (input[i] == 34)
            double_quote++;
        else if (input[i] == 39)
            single_quote++;
        i++;
    }
    if (single_quote % 2 != 0 || double_quote % 2 != 0)
    {
        printf("minishell: open quote\n");
        return (true);
    }
    return (false);
}