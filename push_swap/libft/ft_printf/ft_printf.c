/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwintgen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 10:53:31 by rwintgen          #+#    #+#             */
/*   Updated: 2023/11/13 10:50:35 by rwintgen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_printf(const char *str, ...)
{
	int		i;
	int		cw;
	va_list	ap;

	va_start(ap, str);
	cw = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			cw += ft_format(str[i], ap);
		}
		else
			cw += write(1, &str[i], 1);
		i++;
	}
	va_end(ap);
	return (cw);
}
