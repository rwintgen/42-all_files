/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_param.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalangi <amalangi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 06:00:51 by amalangi          #+#    #+#             */
/*   Updated: 2023/11/13 02:28:53 by amalangi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_param(va_list args, char c)
{
	int	printed_char;

	printed_char = 0;
	if (c == 'c')
		printed_char += ft_printf_char(va_arg(args, int));
	else if (c == 's')
		printed_char += ft_printf_string(va_arg(args, char *));
	else if (c == 'p')
		printed_char += ft_printf_hex_address(va_arg(args, char *));
	else if (c == 'd' || c == 'i')
		printed_char += ft_printf_decimal(va_arg(args, int));
	else if (c == 'u')
		printed_char += ft_printf_unsigned_decimal(va_arg(args, unsigned int));
	else if (c == 'x')
		printed_char += ft_putnbr_base(va_arg(args, unsigned int),
				"0123456789abcdef");
	else if (c == 'X')
		printed_char += ft_putnbr_base(va_arg(args, unsigned int),
				"0123456789ABCDEF");
	else if (c == '%')
		printed_char += ft_printf_char('%');
	return (printed_char);
}
