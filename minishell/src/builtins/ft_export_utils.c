/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwintgen <rwintgen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 13:09:07 by rwintgen          #+#    #+#             */
/*   Updated: 2024/05/30 15:26:55 by rwintgen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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

void	reset_export(t_envp *envp)
{
	t_envp	*tmp;

	tmp = envp;
	while (tmp)
	{
		tmp->is_printed = false;
		tmp = tmp->next;
	}
}

char	*assemble_envar(char *key, char *value)
{
	int		len;
	char	*result;

	if (!value)
		return (ft_strdup(key));
	len = ft_strlen(key) + ft_strlen(value) + 1;
	result = malloc(len);
	if (!result)
		return (NULL);
	ft_strlcpy(result, key, ft_strlen(key) + 1);
	ft_strlcat(result, "=", len);
	ft_strlcat(result, value, len);
	return (result);
}
