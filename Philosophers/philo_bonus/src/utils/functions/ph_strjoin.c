/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwintgen <rwintgen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 14:33:50 by rwintgen          #+#    #+#             */
/*   Updated: 2024/06/27 14:37:39 by rwintgen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

char	*ph_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	int		combsize;
	char	*combstr;

	if (!s1)
		return (NULL);
	combsize = ph_strlen(s1) + ph_strlen(s2) + 1;
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
