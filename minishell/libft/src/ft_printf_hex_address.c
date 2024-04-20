/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hex_address.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalangi <amalangi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 04:12:27 by amalangi          #+#    #+#             */
/*   Updated: 2023/11/13 02:28:54 by amalangi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_hex_address(void *ptr)
{
	int	count;

	if (ptr == NULL)
		return (ft_printf_string("(nil)"));
	count = 0;
	count += ft_printf_string("0x");
	count += ft_putnbr_base((unsigned long long)ptr, "0123456789abcdef");
	return (count);
}
