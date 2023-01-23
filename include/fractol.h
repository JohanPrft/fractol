/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jprofit <jprofit@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 09:35:00 by jprofit           #+#    #+#             */
/*   Updated: 2023/01/16 09:35:00 by jprofit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct	s_point
{
	double	a;
	double	b;
}				t_point;

typedef struct	s_coord_syst
{
	t_point	min;
	t_point	max;
}				t_coord_syst;

typedef struct	s_mlx
{
	void			*mlx;
	void			*win;
	t_coord_syst	win_size;
	t_coord_syst	mandel_size;
	t_data			img;
	double			zoom_factor;
	t_point			cursor_pos;
}				t_mlx;

# include "../mlx/macos/mlx.h"
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

t_mlx	init_all(void);
t_data			create_image(void *mlx, t_coord_syst win_size);

t_point 		convert_point_repere(t_mlx *mlx, t_point point);
double 			divergent_speed (t_mlx *mlx, t_point p);
void			mandelbrot(t_mlx *mlx);

t_point			make_point(double a, double b);
void			mlx_pixel_put_img(t_data *data, int x, int y, int color);

void		modif_image(t_coord_syst win_size, t_data	*img);/******************/

#endif