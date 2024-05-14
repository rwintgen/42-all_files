/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwintgen <rwintgen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 15:36:58 by rwintgen          #+#    #+#             */
/*   Updated: 2024/05/14 14:09:23 by rwintgen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static size_t	ms_strpos(const char *s, int c);
static int		countblock(char *str, char c);
static char		**populate(char **array, char *str, int blocks, char c);

// splits the string s with the char c
char	**ms_split(char *s, char c)
{
	char	**array;
	int		blockcount;

	blockcount = countblock(s, c);
	array = malloc((blockcount + 1) * sizeof(char *));
	if (!array)
		return (NULL);
	array[blockcount] = NULL;
	array = populate(array, s, blockcount, c);
	return (array);
}

// returns the position of the first occurence of c in s
static size_t	ms_strpos(const char *s, int c)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = ft_strlen(s);
	while (i <= len)
	{
		if (s[i] == (unsigned char)c)
			return (i);
		i++;
	}
	return (0);
}

// counts the number of blocks in input for malloc
static int	countblock(char *str, char c)
{
	int		blocks;
	char	q;
	int		i;

	i = 0;
	blocks = 0;
	if (str[0] != c && str[0] != 0)
		blocks++;
	while (str[i])
	{
		if (str[i] == '"' || str[i] == '\'')
		{
			q = str[i];
			i++;
			while (str[i] != q)
				i++;
		}
		if (str[i] == c)
		{
			if (str[i + 1] != c && str[i + 1] != 0)
				blocks++;
		}
		i++;
	}
	return (blocks);
}

// fills the char **array with the blocks of input
static char	**populate(char **array, char *str, int blocks, char c)
{
	int	i;
	int	j;
	int	k;

	j = 0;
	i = 0;
	while (i < blocks)
	{
		k = 0;
		while (str[j] == c)
			j++;
		while (str[j + k] && str[j + k] != c)
		{
			if (str[j + k] == '"' || str[j + k] == '\'')
				k += 1 + ms_strpos(&str[j + k + 1], str[j + k]);
			k++;
		}
		array[i] = ft_substr(str, j, k);
		j = j + k + 1;
		i++;
	}
	return (array);
}
