/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aranger <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 11:28:18 by aranger           #+#    #+#             */
/*   Updated: 2023/10/08 19:40:05 by aranger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include "ft_function.h"

char	*ft_read_file(char *path);
int		ft_checkline(char *str);
int		ft_check_file(char *str);
int		ft_sizeof_file(char *path);
int		ft_empty_line_check(char *str);

char	*ft_read_file(char *path)
{
	int		dict;
	char	*ptn;
	int		size;

	dict = 0;
	size = ft_sizeof_file(path);
	dict = open(path, O_RDONLY);
	if (size != 0)
	{
		ptn = malloc((sizeof(char) * (size + 1)));
		ptn[size] = '\0';
		read(dict, ptn, size);
		close(dict);
		if (ft_check_file(ptn) == 1)
		{
			return (ptn);
		}
		else
		{
			free(ptn);
			return (NULL);
		}
	}
	return (0);
}

int	ft_sizeof_file(char *path)
{
	int		dict;
	int		size;
	char	*buffer;

	buffer = malloc(sizeof(char));
	size = 0;
	dict = open(path, O_RDONLY);
	while (read(dict, buffer, 1))
		size++;
	close(dict);
	free(buffer);
	return (size);
}

int	ft_checkline(char *str)
{
	int	i;

	i = 0;
	while (ft_typeof_char(str[i]) == 1)
		i++;
	while (ft_typeof_char(str[i]) == 3)
		i++;
	if (str[i] == ':')
		i++;
	while (ft_typeof_char(str[i]) == 3)
		i++;
	while (ft_typeof_char(str[i]) == 4 || str[i] == 32)
	{
		i++;
		if (str[i] == '\n')
			return (1);
	}
	return (0);
}

int	ft_check_file(char *str)
{
	int	i;

	i = 0;
	if (ft_checkline(&str[i]) == 0)
		return (0);
	else
	{
		while (str[i] != '\0')
		{
			if (str[i] == '\n' && str[i + 1] != '\0')
			{	
				i++;
				if (ft_checkline(&str[i]) == 0
					&& ft_empty_line_check(&str[i]) == 0)
					return (0);
			}
			i++;
		}
	}
	return (1);
}

int	ft_empty_line_check(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\n')
	{
		if (str[i] > 32 && str[i] <= 126)
			return (0);
		i++;
	}
	return (1);
}
