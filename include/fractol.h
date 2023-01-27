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

typedef struct s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

typedef struct s_point
{
	double	a;
	double	b;
}	t_point;

typedef struct s_coord_syst
{
	t_point	min;
	t_point	max;
}	t_coord_syst;

typedef enum e_mousecode
{
	LEFT_CLICK = 1,
	RIGHT_CLICK = 2,
	SCROLL_IN = 4,
	SCROLL_OUT = 5,
}	t_mousecode;

typedef enum e_keycode
{
	W = 13,
	A = 0,
	S = 1,
	D = 2,
	O = 31,
	P = 35,
	R = 15,
	G = 5,
	B = 11,
	ESQ = 53,
	TAB = 48,
	SPACE = 49,
	PLUS = 69,
	MINUS = 78,
	LEFT = 123,
	RIGHT = 124,
	DOWN = 125,
	UP = 126,
}	t_keycode;

typedef struct s_mlx
{
	void			*mlx;
	void			*win;
	double			(*divergent_speed)(struct s_mlx *, t_point);
	t_coord_syst	win_size;
	t_coord_syst	mandel_size;
	t_data			img;
	t_point			cursor_pos;
	int				max_iter;
	char			fract_arg;
	t_point			offset;
	float			r;
	float			g;
	float			b;
}	t_mlx;

// init.c
int		arg_management(int argc, char **argv, t_mlx *mlx);
t_mlx	init_all(t_mlx *mlx);

// utils.c
int		create_trgb(int t, int r, int g, int b);
int		set_fractale(t_mlx *mlx, char c, char preset);
int		ft_strlen(const char *str);
t_point	make_point(double a, double b);
void	free_and_exit(t_mlx *mlx);

// utils_hook.c
void	add_iteration(t_mlx *mlx);
void	sub_iteration(t_mlx *mlx);
void	mult_mandel_size(t_mlx *mlx, double x);
void	hook_zoom_iter(int keycode, t_mlx *mlx);
void	hook_moove(int keycode, t_mlx *mlx);

// hooks.c
int		key_hook(int keycode, t_mlx *mlx);
int		hook(t_mlx *mlx);
int		mouse_hook(int keycode, int x, int y, t_mlx *mlx);

// draw.c
void	draw_fract(t_mlx *mlx);
t_point	convert_point_repere(t_mlx *mlx, t_point point);

// fractales.c
double	mandelbrot(t_mlx *mlx, t_point c);
double	julia(t_mlx *mlx, t_point c);
double	burning_ship(t_mlx *mlx, t_point c);

#endif