/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printfnbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwintgen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 18:31:18 by rwintgen          #+#    #+#             */
/*   Updated: 2023/11/13 11:40:17 by rwintgen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_printfnbr(int n, char *base)
{
	int		cw;
	int		bn;

	bn = ft_strlen(base);
	if (n < 0)
	{
		if (n == -2147483648)
			return (write(1, "-2147483648", 11));
		write(1, "-", 1);
		return (ft_printfnbr(-n, base) + 1);
	}
	else if (n < bn)
		return (write(1, &base[n], 1));
	else
	{
		cw = ft_printfnbr(n / bn, base);
		return (cw + ft_printfnbr(n % bn, base));
	}
}
