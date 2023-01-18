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

# include "../mlx/macos/mlx.h"
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

t_coord_syst	init_window_size();
t_coord_syst	init_mandel_size(void);
t_data			create_image(void *mlx, t_coord_syst win_size);

t_point 		convert_point_repere(t_coord_syst win_size, t_coord_syst mandel, t_point point);
double 			divergent_speed (t_coord_syst win_size, t_coord_syst mandel_size, t_point p);
void			mandelbrot(t_coord_syst win_size, t_coord_syst mandel_size, t_data	*img);

t_point			make_point(double a, double b);
void			mlx_pixel_put_img(t_data *data, int x, int y, int color);

void		modif_image(t_coord_syst win_size, t_data	*img);/******************/

#endif