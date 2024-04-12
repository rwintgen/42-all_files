/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcannaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 17:38:13 by gcannaud          #+#    #+#             */
/*   Updated: 2023/10/01 21:31:25 by ede-lang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	read(char tab[6][6], int x, int y, char c)
{
	int	tmp;

	tmp = 1;
	while (tmp < 5)
	{
		if (tab[x][tmp] == c)
			return (1);
		else
			tmp++;
	}
	tmp = 1;
	while (tmp < 5)
	{
		if (tab[tmp][y] == c)
			return (1);
		else
			tmp++;
	}
	return (0);
}

int	is_visible_left(char tab[6][6], int x, int y, char h)
{
	int		i;
	int		count;
	char	maxh;

	i = 1;
	count = 0;
	maxh = '0';
	while (i < 5)
	{
		if (i == x && h > maxh)
		{
			maxh = h;
			count++;
		}		
		if (tab[i][y] > maxh && tab[i][y] != '0')
		{
			maxh = tab[i][y];
			count++;
		}
		i++;
	}
	if (count > (tab[0][y] - 48))
		return (1);
	return (0);
}

int	is_visible_right(char tab[6][6], int x, int y, char h)
{
	int		i;
	int		count;
	char	maxh;

	i = 4;
	count = 0;
	maxh = '0';
	while (i > 0)
	{
		if (i == x && h > maxh)
		{
			maxh = h;
			count++;
		}
		if (tab[i][y] > maxh && tab[i][y] != '0')
		{
			maxh = tab[i][y];
			count++;
		}
		i--;
	}
	if (count > (tab[5][y] - 48))
		return (1);
	return (0);
}

int	is_visible_top(char tab[6][6], int x, int y, char h)
{
	int		i;
	int		count;
	char	maxh;

	i = 1;
	count = 0;
	maxh = '0';
	while (i < 5)
	{
		if (i == y && h > maxh)
		{
			maxh = h;
			count++;
		}		
		if (tab[x][i] > maxh && tab[i][y] != '0')
		{
			maxh = tab[x][i];
			count++;
		}
		i++;
	}
	if (count > (tab[x][0] - 48))
		return (1);
	return (0);
}

int	is_visible_bottom(char tab[6][6], int x, int y, char h)
{
	int		i;
	int		count;
	char	maxh;

	i = 4;
	count = 0;
	maxh = '0';
	while (i > 0)
	{
		if (i == y && h > maxh)
		{
			maxh = h;
			count++;
		}
		if (tab[x][i] > maxh && tab[i][y] != '0')
		{
			maxh = tab[x][i];
			count++;
		}
		i--;
	}
	if (count > (tab[x][5] - 48))
		return (1);
	return (0);
}
