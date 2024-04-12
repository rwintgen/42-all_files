/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwintgen <rwintgen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 14:30:07 by rwintgen          #+#    #+#             */
/*   Updated: 2023/12/04 12:13:04 by rwintgen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	ft_strlen(char const *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_bzero(void *s, size_t n)
{
	size_t	i;
	char	*cs;

	cs = s;
	i = 0;
	while (i < n)
	{
		cs[i] = 0;
		i++;
	}
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*start;

	if (nmemb && size && nmemb > (4294967295 / size))
		return (NULL);
	start = malloc(nmemb * size);
	if (!start)
		return (start);
	ft_bzero(start, nmemb * size);
	return (start);
}

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

char	*ft_strchr(const char *s, int c)
{
	size_t	i;
	size_t	len;

	len = ft_strlen(s);
	i = 0;
	while (i <= len)
	{
		if (s[i] == (unsigned char)c)
			return ((char *)&s[i]);
		i++;
	}
	return (NULL);
}
