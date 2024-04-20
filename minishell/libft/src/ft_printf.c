/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalangi <amalangi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 04:35:38 by amalangi          #+#    #+#             */
/*   Updated: 2023/11/13 03:23:01 by amalangi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	return_end(va_list args, int result)
{
	va_end(args);
	return (result);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	va_list	args;
	int		printed_char;

	if (str == NULL)
		return (-1);
	va_start(args, str);
	i = 0;
	printed_char = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '%')
		{
			printed_char += ft_printf_param(args, str[i + 1]);
			i += 2;
			if (i >= (int)ft_strlen(str))
				return (return_end(args, printed_char));
			continue ;
		}
		printed_char += ft_printf_char(str[i]);
		i++;
	}
	va_end(args);
	return (printed_char);
}
