/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwintgen <rwintgen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 15:52:59 by rwintgen          #+#    #+#             */
/*   Updated: 2024/01/31 16:57:49 by rwintgen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "MLX42/MLX42.h"
# include "libft.h"
# include <math.h>

typedef struct s_cam
{
	int		zoom;
	float	scale;

	int		shift_x;
	int		shift_y;
}	t_cam;

typedef struct s_map
{
	int			height;
	int			width;
	int			**altitude;

	int			win_h;
	int			win_w;

	int			proj;
	float		col_shift;

	t_cam		cam;

	mlx_t		*mlx_ptr;
	mlx_image_t	*mlx_img;
}	t_map;

typedef struct s_point
{
	float	x;
	float	y;
	float	z;

	int		col;
}	t_point;

size_t	ft_countwords(char *s, char c);
void	ft_freetab(int **tab, int height);
void	ft_zoom(t_map *map, t_point *orig, t_point *dest);
int		ft_max(float a, float b);
void	ft_add_color(t_point *orig, t_point *dest, t_map *map);
void	ft_put_pixel(t_map *map, t_point pixel);
void	ft_scale(t_map *map, keys_t key);
void	ft_move(t_map *map, keys_t key);
void	ft_rerender(t_map *map);
void	ft_shift(t_point *orig, t_point *dest, t_map *map);
void	ft_color_shift(t_map *map, keys_t key);
void	ft_init_map(t_map *map);
void	ft_maptotab(char *file_name, t_map *map);
void	ft_bresenham(t_map *map, t_point orig, t_point dest);
void	ft_draw_map(t_map *map);
void	ft_mod_key(mlx_key_data_t keydata, void *param);
void	ft_mod_scroll(double xdelta, double ydelta, void *param);
void	ft_err(int argc, char *argv);

#endif
