/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwintgen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 16:22:28 by rwintgen          #+#    #+#             */
/*   Updated: 2023/10/09 17:09:37 by rwintgen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stock_str.h"
#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strdup(char *str)
{
	char	*dest;
	int		length;
	int		i;

	length = ft_strlen(str);
	dest = malloc(sizeof(char) * (length + 1));
	if (dest == NULL)
		return (dest);
	i = 0;
	while (str[i])
	{
		dest[i] = str[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

struct	s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	int			i;
	t_stock_str	*var;

	var = malloc(sizeof(t_stock_str) * (ac + 1));
	if (var == NULL)
		return (var);
	i = 0;
	while (i < ac)
	{
		var[i].size = ft_strlen(av[i]);
		var[i].str = av[i];
		var[i].copy = ft_strdup(av[i]);
		i++;
	}
	var[i].size = 0;
	var[i].str = 0;
	var[i].copy = 0;
	return (var);
}
