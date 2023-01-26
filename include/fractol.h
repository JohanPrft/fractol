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
# include "../mlx/macos/mlx.h"
# include <stdlib.h>
# include <unistd.h>
# include <math.h>
# include <stdio.h> ///////////

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

typedef enum	e_mousecode
{
	LEFT_CLICK = 1,
	RIGHT_CLICK = 2,
	SCROLL_IN = 4,
	SCROLL_OUT = 5,
}				t_mousecode;

typedef enum	e_keycode
{
	W = 13,
	A = 0,
	S = 1,
	D = 2,
	ESQ = 53,
	TAB = 48,
	SPACE = 49,
	PLUS = 69,
	MINUS = 78,
	LEFT = 123,
	RIGHT = 124,
	DOWN = 125,
	UP = 126,
}				t_keycode;

// impossible to use pointer on function because they need t_mlx
typedef struct	s_mlx
{
	int				fract_nb;
	void			*mlx;
	void			*win;
	double 			(*divergent_speed)(struct s_mlx *, t_point);
	t_coord_syst	win_size;
	t_coord_syst	mandel_size;
	t_data			img;
	double			zoom_factor;
	t_point			cursor_pos;
	int				max_iter;
	int 			smooth;
	char 			fract_arg;
	t_point			offset;
}				t_mlx;



t_mlx	init_all(t_mlx *mlx);
void	mult_mandel_size(t_mlx *mlx, double x);
void	add_mandel_size_x(t_mlx *mlx, double x);
void	add_mandel_size_y(t_mlx *mlx, double x);

t_point	convert_point_repere(t_mlx *mlx, t_point point);
void	mlx_pixel_put_img(t_data *data, int x, int y, int color);

int		key_hook(int keycode, t_mlx *mlx);
int		hook(t_mlx *mlx);
int		mouse_hook(int keycode, int x, int y, t_mlx *mlx);

double	mandelbrot(t_mlx *mlx, t_point p);
double	julia(t_mlx *mlx, t_point p);
double	burning_ship(t_mlx *mlx, t_point c);

t_point	make_point(double a, double b);
void 	free_and_exit(t_mlx *mlx);
int		arg_management(int argc, char **argv, t_mlx *mlx);

void	draw_fract(t_mlx *mlx);
void	compute_mandel_size(t_mlx *mlx);

void	modif_image(t_coord_syst win_size, t_data	*img);/******************/

#endif