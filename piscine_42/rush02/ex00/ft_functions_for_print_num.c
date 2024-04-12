/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_functions_for_print_num.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwadie-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 09:52:57 by jwadie-a          #+#    #+#             */
/*   Updated: 2023/10/08 19:59:43 by aranger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_write(int nb, int *arr, char **str);
int		get_order(long int num);
long	ten_to_power(int order);

void	ft_write(int nb, int *arr, char **str)
{
	int	i;
	int	j;

	i = 0;
	while (nb != arr[i])
		i++;
	j = 0;
	while (str[i][j] != '\0')
	{
		while (str[i][j] == ' ')
		{	
			j++;
			if (str[i][j] == '\0')
				return ;
		}
		if (j != 0 && str[i][j - 1] == ' ')
			write(1, " ", 1);
		write(1, &str[i][j], 1);
		j++;
	}
}

int	get_order(long int num)
{
	int	order;

	order = 1;
	while (num / 10)
	{
		order++;
		num /= 10;
	}
	return (order);
}

long	ten_to_power(int order)
{
	int	result;

	result = 1;
	while (order)
	{
		result *= 10;
		order--;
	}
	return (result);
}
