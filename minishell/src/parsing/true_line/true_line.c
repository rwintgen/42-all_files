/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   true_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwintgen <rwintgen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 12:40:53 by deymons           #+#    #+#             */
/*   Updated: 2024/04/23 13:20:37 by rwintgen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

// formats input and expands variables
char	*true_line(char *str, t_sh *sh)
{
	char	*formatted;
	int		missing_spaces;
	int		i;
	int		j;

	missing_spaces = count_missing_spaces(str);
	formatted = malloc(sizeof(char) * (ft_strlen(str) + missing_spaces + 1));
	if (!formatted)
	{
		ft_putstr_fd("minishell: malloc error\n", STDERR_FILENO);
		return (NULL);
	}
	i = 0;
	j = 0;

	printf("\noriginal line:\t\"%s\"\n", str);

	while (str[i])
	{
		if (is_special_char(str[i]))
		{
			if (missing_space_before(str, i))
				formatted[j++] = ' ';
			formatted[j++] = str[i];
			if (missing_space_after(str, i))
				formatted[j++] = ' ';
		}
		else
			formatted[j++] = str[i];
		i++;
	}
	formatted[j] = '\0';
	free(str);

	formatted = replace_dollar(formatted, sh->envp, sh->exit_code);
	printf("formatted line: \"%s\"\n", formatted);
	printf("true line:\t\"%s\"\n\n", formatted);
	return (formatted);
}
