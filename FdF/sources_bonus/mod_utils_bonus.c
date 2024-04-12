/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mod_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwintgen <rwintgen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 17:02:35 by rwintgen          #+#    #+#             */
/*   Updated: 2024/01/31 16:07:34 by rwintgen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

void	ft_scale(t_map *map, keys_t key)
{
	if (key == MLX_KEY_EQUAL)
		map->cam.scale += 0.01;
	if (key == MLX_KEY_MINUS)
		map->cam.scale -= 0.01;
}

void	ft_move(t_map *map, keys_t key)
{
	if (key == MLX_KEY_RIGHT)
		map->cam.shift_x += 1;
	if (key == MLX_KEY_LEFT)
		map->cam.shift_x -= 1;
	if (key == MLX_KEY_DOWN)
		map->cam.shift_y += 1;
	if (key == MLX_KEY_UP)
		map->cam.shift_y -= 1;
}

void	ft_color_shift(t_map *map, keys_t key)
{
	if (key == MLX_KEY_I)
		map->col_shift = 1;
	if (key == MLX_KEY_O)
		map->col_shift = -1;
}

void	ft_rerender(t_map *map)
{
	mlx_delete_image(map->mlx_ptr, map->mlx_img);
	map->mlx_img = mlx_new_image(map->mlx_ptr, map->win_w, map->win_h);
	mlx_image_to_window(map->mlx_ptr, map->mlx_img, 0, 0);
}
