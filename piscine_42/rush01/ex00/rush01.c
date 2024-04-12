/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-lang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 10:28:13 by ede-lang          #+#    #+#             */
/*   Updated: 2023/10/01 21:27:39 by ede-lang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
void	clean(char tab[6][6], int x, int y)
{
	while (y < 5)
	{
		while (x < 5)
		{
			tab[x][y] = '0';
			x++;
		}
		x = 0;
		y++;
	}
}

void	initialize(char tab[6][6])
{
	unsigned int	x;
	unsigned int	y;

	y = 0;
	while (y < 6)
	{
		x = 0;
		while (x < 6)
		{
			tab[x][y] = '0';
			x++;
		}
		y++;
	}
}

void	populate(char tab[6][6], char *paramtab)
{
	unsigned int	i;
	unsigned int	param;

	param = 0;
	i = 0;
	initialize(tab);
	while (param < 16)
	{
		if (paramtab[i] == ' ')
			i++;
		if (param >= 0 && param <= 3)
			tab[param + 1][0] = paramtab[i];
		if (param >= 4 && param <= 7)
			tab[param % 4 + 1][5] = paramtab[i];
		if (param >= 8 && param <= 11)
			tab[0][param % 4 + 1] = paramtab[i];
		if (param >= 12 && param <= 15)
			tab[5][param % 4 + 1] = paramtab[i];
		param++;
		i++;
	}
}

int	is_complete(int *x, int *y)
{
	int	xc;
	int	yc;

	xc = *x;
	yc = *y;
	if (*y < 5)
	{
		if (*x < 4)
			*x += 1;
		else
		{
			if (*y == 4)
				return (0);
			else
			{
				*x = 1;
				*y += 1;
			}
		}
	}
	return (1);
}
