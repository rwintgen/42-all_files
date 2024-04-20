/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalangi <amalangi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 22:37:28 by amalangi          #+#    #+#             */
/*   Updated: 2023/11/02 00:27:08 by amalangi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(const char *string)
{
	int	negative;
	int	i;
	int	nb;

	i = 0;
	negative = 1;
	nb = 0;
	while (string[i] == ' ' || string[i] == '\n' || string[i] == '\t'
		|| string[i] == '\v' || string[i] == '\f' || string[i] == '\r')
		i++;
	if (string[i] == '+' || string[i] == '-')
	{
		if (string[i] == '-')
			negative = negative * -1;
		i++;
	}
	while (string[i] >= 48 && string[i] <= 57)
	{
		nb = nb * 10 + (string[i] - 48);
		i++;
	}
	return (nb * negative);
}
