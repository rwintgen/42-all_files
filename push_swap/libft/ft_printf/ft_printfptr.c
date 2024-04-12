/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printfptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwintgen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 18:08:09 by rwintgen          #+#    #+#             */
/*   Updated: 2023/11/13 12:13:03 by rwintgen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_printfptr(unsigned long n, char *base, int index)
{
	int				cw;
	unsigned int	bn;

	bn = ft_strlen(base);
	if (index == 0 && n == 0)
	{
		write(1, "(nil)", 5);
		return (3);
	}
	else if (index == 0)
		write(1, "0x", 2);
	if (n < bn)
		return (write(1, &base[n], 1));
	else
	{
		cw = ft_printfptr(n / bn, base, index + 1);
		return (cw + ft_printfptr(n % bn, base, index + 1));
	}
}
