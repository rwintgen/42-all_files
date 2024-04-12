/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwintgen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 08:56:16 by rwintgen          #+#    #+#             */
/*   Updated: 2023/09/29 09:47:52 by rwintgen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(char *str)
{
	int	i;
	int	m;
	int	result;

	i = 0;
	m = 0;
	result = 0;
	while (str[i] == ' ' || (str[i] >= 7 && str[i] <= 13))
		i++;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			m++;
		i++;
	}
	while (str [i] != '\0' && (str[i] <= '9' && str[i] >= '0'))
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	if (m % 2 == 1)
		return (result * -1);
	return (result);
}
