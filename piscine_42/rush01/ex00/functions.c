/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-lang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 10:36:08 by ede-lang          #+#    #+#             */
/*   Updated: 2023/10/01 16:56:02 by gcannaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	unsigned int	i;

	i = 0;
	while (str[i])
	{
		ft_putchar(str[i]);
		i++;
	}
}

void	printtab(char tab[6][6])
{
	unsigned int	x;
	unsigned int	y;

	y = 1;
	while (y < 5)
	{
		x = 1;
		while (x <= 5)
		{
			if (x == 5)
				ft_putchar('\n');
			else
			{
				if (tab[x][y] >= '0' && tab[x][y] <= '4')
					ft_putchar(tab[x][y]);
				else
					ft_putchar('x');
				if (x != 4)
					ft_putchar(' ');
			}
			x++;
		}
		y++;
	}
}

int	isvalid(char *str)
{
	unsigned int	i;
	unsigned int	y;

	i = 0;
	y = 0;
	while (str[i])
	{
		if (str[i] == ' ')
		{
			if (str[i + 1] == ' ' || str[0] == ' ')
				return (1);
			i++;
		}
		else if (str[i] >= '1' && str[i] <= '4')
		{
			y++;
			i++;
		}
		else
			return (1);
	}
	if (y != 16)
		return (1);
	return (0);
}
