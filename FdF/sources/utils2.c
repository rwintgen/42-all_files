/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwintgen <rwintgen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 17:59:56 by rwintgen          #+#    #+#             */
/*   Updated: 2024/02/19 16:22:47 by rwintgen         ###   ########.fr       */
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
	map->cam.zoom = 15;
	map->cam.shift_x = ((map->win_w - map->width) / 2) / map->cam.zoom;;
	map->cam.shift_y = ((map->win_h - map->height) / 2) / map->cam.zoom;;
	map->cam.scale = 0.12;
	map->col_shift = 0;
	map->mlx_ptr = mlx_init(map->win_w, map->win_h, "FdF", true);
	map->mlx_img = mlx_new_image(map->mlx_ptr, map->win_w, map->win_h);
}

void	ft_mod_key(mlx_key_data_t keydata, void *param)
{
	t_map	*map_c;

	map_c = param;
	if (keydata.key == MLX_KEY_ESCAPE)
		mlx_close_window(map_c->mlx_ptr);
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
