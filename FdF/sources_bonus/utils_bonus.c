/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwintgen <rwintgen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 16:39:09 by rwintgen          #+#    #+#             */
/*   Updated: 2024/01/31 16:07:42 by rwintgen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

size_t	ft_countwords(char *s, char c)
{
	size_t	i;
	size_t	wc;

	wc = 0;
	i = 0;
	if (s[0] == '\n')
		return (0);
	while (s[i + 1] != '\n')
	{
		if (s[i] == c && s[i + 1] != c)
			wc++;
		i++;
	}
	if (s[0] != c && s[0])
		wc++;
	return (wc);
}

void	ft_freetab(int **tab, int height)
{
	int	i;

	i = 0;
	(void)height;
	if (!tab)
		return ;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

int	ft_max(float a, float b)
{
	if (a < 0)
		a = -a;
	if (b < 0)
		b = -b;
	if (a >= b)
		return (a);
	return (b);
}

void	ft_zoom(t_map *map, t_point *orig, t_point *dest)
{
	orig->x = orig->x * map->cam.zoom;
	orig->y = orig->y * map->cam.zoom;
	dest->x = dest->x * map->cam.zoom;
	dest->y = dest->y * map->cam.zoom;
}

void	ft_err(int argc, char *argv)
{
	int	len;
	int	fd;

	if (argc == 1 || argc > 3)
		exit (1);
	len = ft_strlen(argv) - 4;
	if (len < 1)
		exit (1);
	if (argv[len] != '.' || argv[len + 1] != 'f'
		|| argv[len + 2] != 'd' || argv[len + 3] != 'f')
		exit (1);
	fd = open(argv, O_RDONLY);
}
