/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwintgen <rwintgen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 13:09:07 by rwintgen          #+#    #+#             */
/*   Updated: 2024/05/13 17:47:19 by rwintgen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	err_msg_export(char *arg)
{
	ft_putstr_fd(E_EXPORT_ID, STDERR_FILENO);
	ft_putendl_fd(arg, STDERR_FILENO);
	return (1);
}

bool	is_invalid_key(char *key)
{
	int	i;

	i = 0;
	if (!key || !key[0])
		return (true);
	if (key[0] && !ft_isalpha(key[0]) && key[0] != '_')
		return (true);
	while (key[i])
	{
		if (!ft_isalnum(key[i]) && key[i] != '_')
			return (true);
		i++;
	}
	return (false);
}

char	*get_key(char *arg)
{
	int		i;
	char	*key;

	i = 0;
	while (arg[i] && arg[i] != '=')
		i++;
	key = ft_substr(arg, 0, i);
	return (key);
}

char	*get_value(char *arg)
{
	int		i;
	char	*value;

	i = 0;
	while (arg[i] && arg[i] != '=')
		i++;
	if (!arg[i])
		return (NULL);
	value = ft_strdup(arg + i + 1);
	return (value);
}
