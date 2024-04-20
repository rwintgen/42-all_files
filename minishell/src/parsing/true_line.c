/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   true_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwintgen <rwintgen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 12:40:53 by deymons           #+#    #+#             */
/*   Updated: 2024/04/20 13:46:21 by rwintgen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static int	missing_space_before(char *str, int i)
{
	if (i == 0)
		return (false);
	if (str[i - 1] != ' ' && !is_special_char(str[i - 1]))
		return (true);
	return (false);
}

static int	missing_space_after(char *str, int i)
{
	if (str[i + 1] == '\0') return false;
	if (str[i + 1] != ' ' && !is_special_char(str[i + 1]))
		return (true);
	if (is_special_char(str[i + 1]) && str[i] != str[i + 1])
		return (true);
	return (false);
}

static int	count_missing_spaces(char *str)
{
	int i;
	int count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (is_special_char(str[i]))
		{
			count += missing_space_before(str, i);
			count += missing_space_after(str, i);
		}
		i++;
	}
	return (count);
}

char	*true_line(char *str, t_sh *sh)
{
	char    *formatted;
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
