/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_char_tab.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwintgen <rwintgen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 13:46:44 by rwintgen          #+#    #+#             */
/*   Updated: 2024/03/13 11:59:11 by rwintgen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_free_char_tab(char **tab)
{
	int	i;

	i = 0;
	if (!tab)
		exit(1);
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}
