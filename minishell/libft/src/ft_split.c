/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalangi <amalangi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 07:41:18 by amalangi          #+#    #+#             */
/*   Updated: 2023/11/05 04:40:34 by amalangi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// int main()
// {
// 	char *s = "      split       this for   me  !       ";

// 	char **result = ft_split(s, ' ');
// 	if (!result)
// 		printf("TEST_SUCCESS");
// 	printf("TEST_FAILED");
// 	return 0;
// }

static int	is_char(char c, char to_find)
{
	if (c == to_find)
		return (1);
	if (c == '\0')
		return (1);
	return (0);
}

static int	count_words(char const *str, char c)
{
	int	i;
	int	words;

	words = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (is_char(str[i + 1], c) == 1
			&& is_char(str[i], c) == 0)
			words++;
		i++;
	}
	return (words);
}

void	write_word(char *dest, char const *from, char c)
{
	int	i;

	i = 0;
	while (is_char(from[i], c) == 0)
	{
		dest[i] = from[i];
		i++;
	}
	dest[i] = '\0';
}

void	write_split(char **split, char const *s, char c)
{
	int		i;
	int		j;
	int		word;

	word = 0;
	i = 0;
	while (s[i] != '\0')
	{
		if (is_char(s[i], c) == 1)
			i++;
		else
		{
			j = 0;
			while (is_char(s[i + j], c) == 0)
				j++;
			split[word] = malloc(sizeof(char) * (j + 1));
			write_word(split[word], s + i, c);
			i += j;
			word++;
		}
	}
}

char	**ft_split(char const *s, char c)
{
	char	**ptr;
	int		words;

	if (!s)
		return (NULL);
	words = count_words(s, c);
	ptr = malloc(sizeof(char *) * (words + 1));
	if (!ptr)
		return (NULL);
	ptr[words] = 0;
	write_split(ptr, s, c);
	return (ptr);
}
