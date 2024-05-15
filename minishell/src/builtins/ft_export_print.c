/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export_print.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwintgen <rwintgen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 13:07:17 by rwintgen          #+#    #+#             */
/*   Updated: 2024/05/15 12:42:53 by rwintgen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	print_key(char *key);
static void	print_value(char *value);

void	print_export(t_envp *envp)
{
	t_envp	*tmp;
	t_envp	*first;

	tmp = envp;
	first = NULL;
	while (tmp)
	{
		if (!tmp->is_printed)
		{
			if (!first || ft_strcmp(tmp->key, first->key) < 0)
				first = tmp;
		}
		tmp = tmp->next;
	}
	if (!first)
		return ;
	print_key(first->key);
	print_value(first->value);
	first->is_printed = true;
	return (print_export(envp));
}

static void	print_key(char *key)
{
	ft_putstr_fd("declare -x ", STDOUT_FILENO);
	ft_putstr_fd(key, STDOUT_FILENO);
}

static void	print_value(char *value)
{
	if (value)
	{
		ft_putstr_fd("=\"", STDOUT_FILENO);
		ft_putstr_fd(value, STDOUT_FILENO);
		ft_putstr_fd("\"\n", STDOUT_FILENO);
	}
	else
		ft_putstr_fd("\n", STDOUT_FILENO);
}
