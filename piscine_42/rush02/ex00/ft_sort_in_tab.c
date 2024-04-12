/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_in_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aranger <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 19:14:32 by aranger           #+#    #+#             */
/*   Updated: 2023/10/08 15:23:20 by aranger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_function.h"
#include <stdlib.h>

char	*ft_read_file(void);
int		ft_strlen2(char *str);
char	**ft_store_str(char *str);
int		*ft_store_int(char *str);
int		ft_empty_line_check(char *str);

int	ft_strlen2(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\n')
	{
		i++;
	}
	return (i);
}

char	**ft_store_str(char *str)
{
	int		i;
	int		j;
	int		k;
	char	**tab;

	j = 0;
	i = 0;
	tab = malloc((sizeof(char *) * ft_count_lines(str)));
	while (str[i] != '\0')
	{
		while (str[i] == 32 || ft_typeof_char(str[i]) == 1 || str[i] == ':')
			i++;
		tab[j] = malloc((sizeof(char) * ft_strlen2(&str[i])) + 1);
		k = 0;
		while (str[i] != '\n')
		{
			tab[j][k] = str[i];
			k++;
			i++;
		}
		tab[j][k] = '\0';
		i++;
		j++;
	}
	return (tab);
}

int	*ft_store_int(char *str)
{	
	int	i;
	int	j;
	int	*tab;

	i = 0;
	j = 0;
	tab = malloc(sizeof(int) * ft_count_lines(str));
	while (str[i] != '\0')
	{	
		if (ft_empty_line_check(&str[i]) == 0)
			tab[j] = ft_atoi_2(&str[i]);
		else
			tab[j] = -1;
		while (str[i] != '\n')
		{
			i++;
		}
		i++;
		j++;
	}
	return (tab);
}
