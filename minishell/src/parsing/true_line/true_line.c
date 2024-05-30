/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   true_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwintgen <rwintgen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 12:40:53 by deymons           #+#    #+#             */
/*   Updated: 2024/05/30 17:59:27 by rwintgen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	add_spaces(char **formatted, char *str);

// formats input and expands variables
char	*true_line(char *str, t_sh *sh)
{
	char	*formatted;
	int		missing_spaces;

	missing_spaces = count_missing_spaces(str);
	formatted = malloc(sizeof(char) * (ft_strlen(str) + missing_spaces + 1));
	if (!formatted)
	{
		ft_putendl_fd(E_MALLOC, STDERR_FILENO);
		return (NULL);
	}
	add_spaces(&formatted, str);
	free(str);
	formatted = var_expand(formatted, sh->envp, sh->exit_code, 0);
	return (formatted);
}

// adds spaces in input where needed
static void	add_spaces(char **formatted, char *str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i])
	{
		if (is_whitespace(str[i]))
			(*formatted)[j++] = ' ';
		else if (is_special_char(str[i]))
		{
			if (missing_space_before(str, i))
				(*formatted)[j++] = ' ';
			(*formatted)[j++] = str[i];
			if (missing_space_after(str, i))
				(*formatted)[j++] = ' ';
		}
		else
			(*formatted)[j++] = str[i];
		i++;
	}
	(*formatted)[j] = '\0';
}
