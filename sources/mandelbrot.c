/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imac <imac@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 15:44:00 by jprofit           #+#    #+#             */
/*   Updated: 2023/01/23 10:36:29 by imac             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

t_point convert_point_repere(t_mlx *mlx, t_point point)
{
	point.a = point.a * ((mlx->mandel_size.max.a - mlx->mandel_size.min.a) / (mlx->win_size.max.a * mlx->zoom_factor)) - mlx->mandel_size.max.a;
	point.b = point.b * ((mlx->mandel_size.max.b - mlx->mandel_size.min.b) / (mlx->win_size.max.b * mlx->zoom_factor)) - mlx->mandel_size.max.b;
	return (point);
}

double divergent_speed(t_mlx *mlx, t_point p)
{
	int 	max_iter;
	t_point	z;
	int 	i;

	p = convert_point_repere(mlx, p);
	z = make_point(0, 0); //essayer d'autres valeurs
	max_iter = 30;
	i = 0;
	while (++i < max_iter)
	{
		z = make_point(z.a * z.a - z.b * z.b + p.a, 2 * z.a * z.b + p.b);
		if (z.a * z.a + z.b * z.b > 4)
		{
			return ((double)i / max_iter / 4);
		}
	}
	return (0);
}

void	mandelbrot(t_mlx *mlx)
{
	int		i;
	int 	j;
	double 	div;

	i = (int)mlx->win_size.max.b + 1;
	while (--i >= 0)
	{
		j = (int)mlx->win_size.max.a + 1;
		while (--j >= 0)
		{
			div = divergent_speed(mlx, make_point(j, i));
			mlx_pixel_put_img(&mlx->img, j, i, 0x008585 * div);
		}
	}
}

void	mandelbrot_zoom_up(t_mlx mlx)
{
	(void)mlx;
}
