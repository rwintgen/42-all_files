/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwintgen <rwintgen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 14:29:44 by rwintgen          #+#    #+#             */
/*   Updated: 2023/12/07 11:21:57 by rwintgen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*get_next_line(int fd)
{
	static char	*str[1024];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	str[fd] = ft_buftostr(str[fd], fd);
	if (!str[fd])
		return (NULL);
	line = ft_getline(str[fd]);
	str[fd] = ft_clear(str[fd]);
	return (line);
}

char	*joinandfree(char *str, char *buf)
{
	char	*tmp;

	tmp = ft_strjoin((const char *)str, (const char *)buf);
	free(str);
	return (tmp);
}

char	*ft_buftostr(char *str, int fd)
{
	int		chrd;
	char	*buf;

	buf = ft_calloc(sizeof(char), BUFFER_SIZE + 1);
	chrd = 1;
	if (!str)
		str = ft_calloc(sizeof(char), 1);
	while (chrd != 0 && !ft_strchr(buf, '\n'))
	{
		chrd = read(fd, buf, BUFFER_SIZE);
		if (chrd == -1)
		{
			free(str);
			free(buf);
			return (NULL);
		}
		buf[chrd] = '\0';
		str = joinandfree(str, buf);
	}
	free(buf);
	return (str);
}

char	*ft_getline(char *str)
{
	int		i;
	char	*line;

	i = 0;
	if (!str[i])
		return (NULL);
	while (str[i] && str[i] != '\n')
		i++;
	line = ft_calloc(sizeof(char), (i + 2));
	if (!str)
		return (NULL);
	i = 0;
	while (str[i] && str[i] != '\n')
	{
		line[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
	{
		line[i] = str[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*ft_clear(char *str)
{
	int		i;
	int		j;
	char	*nstr;

	if (!str)
		return (NULL);
	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (!str[i])
	{
		free(str);
		return (NULL);
	}
	nstr = ft_calloc(sizeof(char), ft_strlen(str) - i + 1);
	if (!nstr)
		return (NULL);
	i++;
	j = 0;
	while (str[i])
		nstr[j++] = str[i++];
	free (str);
	return (nstr);
}
