/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_unsigned_decimal.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalangi <amalangi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 04:18:38 by amalangi          #+#    #+#             */
/*   Updated: 2023/11/13 02:29:29 by amalangi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_unsigned_decimal(unsigned int nb)
{
	int			i;
	long long	n;

	i = 0;
	n = nb;
	if (n >= 10)
		i += ft_printf_unsigned_decimal(n / 10);
	i += ft_printf_char(n % 10 + '0');
	return (i);
}
