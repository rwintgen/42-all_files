/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalangi <amalangi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 06:48:59 by amalangi          #+#    #+#             */
/*   Updated: 2023/11/05 04:00:21 by amalangi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// int main()
// {
// 	char *s1 = "  \t \t \n   \n\n\n\t";
// 	char *s2 = "";
// 	char *ret = ft_strtrim(s1, " \n\t");

// 	printf("ft_strtrim : %s, strtrim : %s", ret, s2);
// 	if (!strcmp(ret, s2))
// 		printf("\nSUCCESS\n");
// 	printf("\nECHEC\n");
// 	return (0);
// }

static int	is_char(char c, const char *search)
{
	size_t	i;

	i = 0;
	while (search[i])
	{
		if (search[i] == c)
			return (1);
		i++;
	}
	return (0);
}

static size_t	set_selector(char const *s1, char const *set, int meth)
{
	size_t	i;

	if (meth == 0)
	{
		i = 0;
		while (is_char(s1[i], set) == 1)
			i++;
	}
	if (meth == 1)
	{
		i = ft_strlen(s1);
		while (is_char(s1[i -1], set) == 1)
			i--;
	}
	return (i);
}

static char	*generate(char const *s1, size_t i, size_t k)
{
	char	*str;

	if (i < k)
		str = malloc((ft_strlen(s1) - i - (
						ft_strlen(s1) - k) + 1) * sizeof(char));
	else
		str = malloc(1 * sizeof(char));
	return (str);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*string;
	size_t	i;
	size_t	j;
	size_t	k;

	if (!s1 || !set)
		return (NULL);
	i = set_selector(s1, set, 0);
	k = set_selector(s1, set, 1);
	j = 0;
	string = generate(s1, i, k);
	if (string)
	{
		while (s1[i] != '\0' && i < k)
		{
			string[j] = s1[i];
			j++;
			i++;
		}
		string[j] = '\0';
		return (string);
	}
	return (NULL);
}
