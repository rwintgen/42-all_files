/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwintgen <rwintgen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 11:51:10 by rwintgen          #+#    #+#             */
/*   Updated: 2024/01/31 17:06:22 by rwintgen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

void	ft_iso_line(t_point	*orig, t_point *dest, t_map *map)
{
	float	orig_x;
	float	orig_y;
	float	dest_x;
	float	dest_y;

	orig_x = orig->x;
	orig_y = orig->y;
	dest_x = dest->x;
	dest_y = dest->y;
	orig->x = (orig_x - orig_y) * cos(0.523599);
	orig->y = (orig_x + orig_y) * sin(0.523599) - orig->z * map->cam.scale;
	dest->x = (dest_x - dest_y) * cos(0.523599);
	dest->y = (dest_x + dest_y) * sin(0.523599) - dest->z * map->cam.scale;
}

void	ft_bresenham(t_map *map, t_point orig, t_point dest)
{
	float	delta_x;
	float	delta_y;
	int		max;

	orig.z = map->altitude[(int)orig.y][(int)orig.x];
	dest.z = map->altitude[(int)dest.y][(int)dest.x];
	orig.col = 0xFFFFFFFF;
	if (!map->proj)
		ft_iso_line(&orig, &dest, map);
	ft_shift(&orig, &dest, map);
	ft_zoom(map, &orig, &dest);
	delta_x = (dest.x - orig.x);
	delta_y = (dest.y - orig.y);
	max = ft_max(delta_x, delta_y);
	delta_x = delta_x / max;
	delta_y = delta_y / max;
	while ((int)(orig.x - dest.x) || (int)(orig.y - dest.y))
	{
		ft_put_pixel(map, orig);
		orig.x += delta_x;
		orig.y += delta_y;
	}
}

void	ft_draw_map(t_map *map)
{
	t_point	ref;
	t_point	v;
	t_point	h;

	ref.y = 0;
	while (ref.y < map->height)
	{
		ref.x = 0;
		v = ref;
		h = ref;
		v.y = ref.y + 1;
		while (ref.x < map->width)
		{
			h.x = ref.x + 1;
			if (ref.x < map->width -1)
				ft_bresenham(map, ref, h);
			if (ref.y < map->height -1)
				ft_bresenham(map, ref, v);
			ref.x++;
			v.x++;
		}
		ref.y++;
	}
}
