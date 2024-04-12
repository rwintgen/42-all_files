/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush03.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-lang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 10:07:45 by ede-lang          #+#    #+#             */
/*   Updated: 2023/09/23 17:31:41 by rwintgen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
void	ft_putchar(char c);
char	whatchar(int l, int h, int il, int ih);

void	rush(int l, int h)
{
	int	il;
	int	ih;

	ih = 0;
	while (ih < h)
	{
		il = 0;
		while (il <= l)
		{
			ft_putchar(whatchar(l, h, il, ih));
			il++;
		}
		ih++;
	}
}

char	whatchar(int l, int h, int il, int ih)
{
	char	*chara;

	chara = "ABCBAC";
	if (ih == 0 && il == 0)
		return (chara[0]);
	else if ((ih == 0 || ih == h - 1) && il != 0 && il < l - 1)
		return (chara[1]);
	else if (ih == 0 && il == l - 1)
		return (chara[2]);
	else if (il == l)
		return ('\n');
	else if (ih > 0 && ih < h - 1)
	{
		if (il == 0 || il == l - 1)
			return (chara[3]);
		else
			return (' ');
	}
	else if (ih == h - 1 && il == 0)
		return (chara[4]);
	else if (ih == h - 1 && il == l - 1)
		return (chara[5]);
	return ('\0');
}
