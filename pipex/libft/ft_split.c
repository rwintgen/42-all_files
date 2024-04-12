/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwintgen <rwintgen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 16:47:24 by rwintgen          #+#    #+#             */
/*   Updated: 2024/03/13 13:17:43 by rwintgen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_countwords(const char *s, char c)
{
	size_t	i;
	size_t	wc;

	wc = 0;
	i = 0;
	if (s[0] == '\0')
		return (0);
	while (s[i + 1])
	{
		if (s[i] == c && s[i + 1] != c)
			wc++;
		i++;
	}
	if (s[0] != c && s[0])
		wc++;
	return (wc);
}

static size_t	ft_wordlen(const char *s, char c)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		i++;
		if (s[i] == c)
			break ;
	}
	return (i);
}

static void	ft_freetab(char **tab)
{
	int	i;

	i = 0;
	if (!tab)
		return ;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

static char	**ft_populate(const char *s, char c, char **dest, size_t size)
{
	size_t	i;
	size_t	d;

	i = 0;
	d = 0;
	while (d < size)
	{
		while (s[i] && s[i] == c)
			i++;
		dest[d] = ft_substr(s, i, ft_wordlen(&s[i], c));
		if (!dest[d])
		{
			ft_freetab(dest);
			return (NULL);
		}
		while (s[i] && s[i] != c)
			i++;
		d++;
	}
	dest[d] = NULL;
	return (dest);
}

char	**ft_split(char const *s, char c)
{
	char	**tab;
	int		size;

	if (!s)
		return (NULL);
	size = ft_countwords((char *)s, c);
	tab = malloc(sizeof(char *) * (size + 1));
	if (!tab)
		return (NULL);
	tab = ft_populate(s, c, tab, size);
	return (tab);
}
