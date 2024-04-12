/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_function.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aranger <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 22:17:18 by aranger           #+#    #+#             */
/*   Updated: 2023/10/08 19:10:15 by aranger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_typeof_char(char c)
{
	if (c >= 48 && c <= 57)
		return (1);
	else if (c == '-' || c == '+')
		return (2);
	else if (c == '\t' || c == '\n' || c == '\v'
		|| c == '\f' || c == '\r' || c == 32)
		return (3);
	else if (c >= 32 && c <= 126)
		return (4);
	else
		return (0);
}

long int	ft_atoi_2(char *str)
{
	long int	i;
	long int	result;

	i = 0;
	result = 0;
	while (str[i] == ' ' || (str[i] >= 7 && str[i] <= 13))
		i++;
	if (str[i] == '+')
		i++;
	while (str [i] != 32 && (str[i] <= '9' && str[i] >= '0'))
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return (result);
}

int	ft_count_lines(char *str)
{
	int	i;
	int	nlin;

	i = 0;
	nlin = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '\n')
			nlin++;
		i++;
	}
	return (nlin);
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		write(2, &str[i], 1);
		i++;
	}
}
