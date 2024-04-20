/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalangi <amalangi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 04:13:14 by amalangi          #+#    #+#             */
/*   Updated: 2023/11/15 02:10:40 by amalangi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_base(unsigned long long nb, char *base)
{
	int	i;
	int	len;

	i = 0;
	len = ft_strlen(base);
	if (nb >= (unsigned long long)len)
		i += ft_putnbr_base(nb / len, base);
	i += ft_printf_char(base[nb % len]);
	return (i);
}
