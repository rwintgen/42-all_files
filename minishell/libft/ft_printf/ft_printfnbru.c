/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printfnbru.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwintgen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 18:32:37 by rwintgen          #+#    #+#             */
/*   Updated: 2023/11/09 18:34:36 by rwintgen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_printfnbru(unsigned int n, char *base)
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
