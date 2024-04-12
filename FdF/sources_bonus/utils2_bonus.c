/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwintgen <rwintgen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 17:59:56 by rwintgen          #+#    #+#             */
/*   Updated: 2024/02/19 16:32:05 by rwintgen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

void	ft_init_map(t_map *map, char **argv)
{
	map->win_w = 1500;
	map->win_h = 1000;
	if (argv[2])
		map->proj = ft_atoi(argv[2]);
	else
		map->proj = 0;
	map->cam.zoom = 1;
	map->cam.shift_x = ((map->win_w - map->width) / 2) / map->cam.zoom;
	map->cam.shift_y = ((map->win_h - map->width) / 2) / map->cam.zoom;
	map->cam.scale = 0.12;
	map->col_shift = 0;
	map->mlx_ptr = mlx_init(map->win_w, map->win_h, "FdF", true);
	map->mlx_img = mlx_new_image(map->mlx_ptr, map->win_w, map->win_h);
}

void	ft_add_color(t_point *orig, t_point *dest, t_map *map)
{
	int	altitude;

	altitude = dest->z + orig->z;
	orig->col = 0xFFFFFFFF;
	if (altitude > 257)
		altitude = 257;
	if (orig->z || dest->z)
		orig->col -= 0xFF00 * ((altitude) * map->col_shift);
}

void	ft_put_pixel(t_map *map, t_point pixel)
{
	if (pixel.y > map->win_h || pixel.x > map->win_w
		|| pixel.y < 0 || pixel.x < 0)
		return ;
	mlx_put_pixel(map->mlx_img, pixel.x, pixel.y, pixel.col);
}

void	ft_shift(t_point *orig, t_point *dest, t_map *map)
{
	orig->x += map->cam.shift_x;
	orig->y += map->cam.shift_y;
	dest->x += map->cam.shift_x;
	dest->y += map->cam.shift_y;
}
