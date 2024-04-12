/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printfnbrhex.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwintgen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 18:33:19 by rwintgen          #+#    #+#             */
/*   Updated: 2023/11/13 11:43:28 by rwintgen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_printfnbrhex(unsigned int n, char *base)
{
	int				cw;
	unsigned int	bn;

	bn = ft_strlen(base);
	if (n < bn)
		return (write(1, &base[n], 1));
	else
	{
		cw = ft_printfnbr(n / bn, base);
		return (cw + ft_printfnbr(n % bn, base));
	}
}
