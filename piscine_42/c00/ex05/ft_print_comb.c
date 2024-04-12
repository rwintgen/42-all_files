/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwintgen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 17:17:13 by rwintgen          #+#    #+#             */
/*   Updated: 2023/09/21 08:40:17 by rwintgen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	write_n(char a, char b, char c);
void	ft_print_comb(void);

void	ft_print_comb(void)
{
	char	a;
	char	b;
	char	c;

	a = '0';
	while (a <= '7')
	{
		b = '0';
		while (b <= '8')
		{	
			c = '0';
			while (c < '9')
			{
				c++;
				write_n(a, b, c);
			}
			b++;
		}
		a++;
	}
}

void	write_n(char a, char b, char c)
{
	if ((a != b && b != c && a != c) && (a < b && b < c))
	{
		write (1, &a, 1);
		write (1, &b, 1);
		write (1, &c, 1);
		if (a != '7')
			write (1, ", ", 2);
	}
}
