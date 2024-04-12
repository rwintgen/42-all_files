/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_islegit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwintgen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 10:01:20 by rwintgen          #+#    #+#             */
/*   Updated: 2023/10/08 16:41:37 by aranger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	islegit(int argc, char **argv);
int	nbverif(char *str);

int	islegit(int argc, char **argv)
{
	if (argc < 2 || argc > 3)
		return (1);
	if (argc == 2)
	{
		if (nbverif(argv[1]) == 1)
			return (1);
	}
	if (argc == 3)
	{
		if (nbverif(argv[2]) == 1)
			return (1);
	}
	return (0);
}

int	nbverif(char *str)
{
	int	i;
	int	j;

	i = 0;
	while (str[i] == ' ' || (str[i] >= 7 && str[i] <= 13))
		i++;
	if ((str[i] == '-' || str[i] == '+') || (str [i] < '0' || str[i] > '9'))
	{
		if (str[i] == '+' && (str [i + 1] >= '0' && str[i + 1] <= '9'))
			i++;
		else
			return (1);
	}
	j = 0;
	while (str[i + j] != '\0' && (str[i + j] >= '0' && str[i + j] <= '9'))
	{
		j++;
	}
	if (j > 12 || str[i + j] == '.' || str[i + j] == ',')
		return (1);
	return (0);
}
