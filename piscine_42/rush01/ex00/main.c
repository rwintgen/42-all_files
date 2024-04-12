/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-lang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 11:21:23 by ede-lang          #+#    #+#             */
/*   Updated: 2023/10/01 21:31:01 by ede-lang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
void	ft_putstr(char *str);
void	populate(char tab[6][6], char *paramtab);
void	printtab(char tab[6][6]);
int		resolve(char tab[6][6], int x, int y, char c);

int		isvalid(char *str);

int	main(int argc, char *argv[])
{
	char	tab[6][6];

	if (argc != 2 || isvalid(argv[1]) == 1)
	{
		ft_putstr("Error\n");
		return (1);
	}
	else
	{
		populate(tab, argv[1]);
		tab[1][1] = '0';
		if (resolve(tab, 1, 1, '1') == 0)
		{
			printtab(tab);
			return (0);
		}
		else
		{
			ft_putstr("Error\n");
			return (1);
		}
	}
}
