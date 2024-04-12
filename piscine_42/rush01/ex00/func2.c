/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-lang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 15:33:50 by ede-lang          #+#    #+#             */
/*   Updated: 2023/10/01 21:30:08 by ede-lang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
int		read(char tab[6][6], int x, int y, char c);
int		is_visible_left(char tab[6][6], int x, int y, char h);
int		is_visible_right(char tab[6][6], int x, int y, char h);
int		is_visible_top(char tab[6][6], int x, int y, char h);
int		is_visible_bottom(char tab[6][6], int x, int y, char h);
int		is_complete(int *x, int *y);
void	clean(char tab[6][6], int x, int y);
void	printtab(char tab[6][6]);

int	isvalidplacement(char tab[6][6], int x, int y, char val)
{
	if (read(tab, x, y, val) == 1)
		return (1);
	if (is_visible_left(tab, x, y, val) == 1
		|| is_visible_right(tab, x, y, val) == 1
		|| is_visible_top(tab, x, y, val) == 1
		|| is_visible_bottom(tab, x, y, val) == 1)
		return (1);
	return (0);
}

int	resolve(char tab[6][6], int x, int y, char c)
{
	int		xc;
	int		yc;

	clean(tab, x, y);
	while (c <= '4')
	{
		xc = x;
		yc = y;
		if (isvalidplacement(tab, x, y, c) == 0)
		{
			tab[x][y] = c;
			if (is_complete(&xc, &yc) == 0)
				return (0);
			else if (resolve(tab, xc, yc, '1') == 0)
				return (0);
			else
				return (1);
		}
		c++;
	}
	return (1);
}
