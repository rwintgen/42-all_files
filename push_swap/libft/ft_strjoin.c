/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwintgen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 09:26:58 by rwintgen          #+#    #+#             */
/*   Updated: 2023/11/07 13:12:37 by rwintgen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	int		combsize;
	char	*combstr;

	if (!s1)
		return (NULL);
	combsize = ft_strlen(s1) + ft_strlen(s2) + 1;
	combstr = malloc(sizeof(char) * combsize);
	if (!combstr)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i])
	{
		combstr[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		combstr[i + j] = s2[j];
		j++;
	}
	combstr[i + j] = '\0';
	return (combstr);
}
