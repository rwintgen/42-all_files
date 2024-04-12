/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_num.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwadie-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 09:53:42 by jwadie-a          #+#    #+#             */
/*   Updated: 2023/10/08 15:08:43 by aranger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		get_order(long int num);
long	ten_to_power(int order);
void	ft_write(int nb, int *arr, char **str);
void	ft_print_num(long int num, int *arr, char **dict);
void	ft_print_threes(int num, int *arr, char **dict);
void	ft_print_twos(int rest, int *arr, char **dict);
void	ft_print_thousands(int order, int *arr, char **dict);

void	ft_print_num(long int num, int *arr, char **dict)
{
	int	order;
	int	n;

	order = get_order(num);
	if (num == 0)
		ft_write(0, arr, dict);
	while (order)
	{
		if (order % 3)
			order -= order % 3;
		else
			order -= 3;
		n = num / ten_to_power(order);
		ft_print_threes(n, arr, dict);
		if (order && n)
			write(1, " ", 1);
		num = num - n * ten_to_power(order);
		if (n)
		{	
			ft_print_thousands(order, arr, dict);
			if (num)
				write(1, " ", 1);
		}
	}
}

void	ft_print_threes(int num, int *arr, char **dict)
{
	int	hundreds;
	int	rest;

	hundreds = num / 100;
	rest = num - hundreds * 100;
	if (hundreds)
	{
		ft_write(hundreds, arr, dict);
		write(1, " ", 1);
		ft_write(100, arr, dict);
		if (rest)
			write(1, " ", 1);
	}
	if (rest)
		ft_print_twos(rest, arr, dict);
}

void	ft_print_twos(int rest, int *arr, char **dict)
{
	int	tens;

	tens = rest / 10;
	if (rest == 0)
		return ;
	if (rest <= 20)
		ft_write(rest, arr, dict);
	else
	{
		ft_write(tens * 10, arr, dict);
		if (rest - 10 * tens)
		{
			write(1, " ", 1);
			ft_write(rest - 10 * tens, arr, dict);
		}
	}
}

void	ft_print_thousands(int order, int *arr, char **dict)
{
	if (order == 0)
		return ;
	if (order == 3)
		ft_write(1000, arr, dict);
	if (order == 6)
		ft_write(1000000, arr, dict);
	if (order == 9)
		ft_write(1000000000, arr, dict);
}
