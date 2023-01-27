/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractales.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jprofit <jprofit@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 17:17:00 by jprofit           #+#    #+#             */
/*   Updated: 2023/01/24 17:17:00 by jprofit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

double	mandelbrot(t_mlx *mlx, t_point c)
{
	t_point	z;
	t_point	z_square;
	int		i;

	c = convert_point_repere(mlx, c);
	z = make_point(0, 0);
	z_square = make_point(z.a * z.a, z.b * z.b);
	i = 0;
	while (++i < mlx->max_iter)
	{
		z = make_point(z_square.a - z_square.b + c.a, 2 * z.a * z.b + c.b);
		z_square = make_point(z.a * z.a, z.b * z.b);
		if (z_square.a + z_square.b > 4)
		{
			return ((double)i / mlx->max_iter);
		}
	}
	return (0);
}

t_point	choose_preset(t_mlx *mlx)
{
	t_point	p;

	if (mlx->fract_arg == '0')
		p = make_point(-0.8, 0.156);
	else if (mlx->fract_arg == '1')
		p = make_point(0.285, 0.01);
	else if (mlx->fract_arg == '2')
		p = make_point(-0.7269, 0.1889);
	else if (mlx->fract_arg == '3')
		p = make_point(0, -0.8);
	else
		p = make_point(-0.8, 0.156);
	return (p);
}

double	julia(t_mlx *mlx, t_point c)
{
	t_point	z;
	t_point	z_square;
	t_point	preset;
	int		i;

	preset = choose_preset(mlx);
	c = convert_point_repere(mlx, c);
	z = c;
	z_square = make_point(z.a * z.a, z.b * z.b);
	i = 0;
	while (++i < mlx->max_iter)
	{
		z = make_point(z_square.a - z_square.b + preset.a, \
		2 * z.a * z.b + preset.b);
		z_square = make_point(z.a * z.a, z.b * z.b);
		if (z_square.a + z_square.b > 4)
		{
			return ((double)i / mlx->max_iter);
		}
	}
	return (0);
}

double	burning_ship(t_mlx *mlx, t_point c)
{
	t_point	z;
	t_point	z_square;
	int		i;

	c = convert_point_repere(mlx, c);
	z = make_point(0, 0);
	z_square = make_point(z.a * z.a, z.b * z.b);
	i = 0;
	while (++i < mlx->max_iter)
	{
		z = make_point(fabs(z_square.a) - fabs(z_square.b) + c.a, \
		2 * fabs(z.a) * fabs(z.b) + c.b);
		z_square = make_point(z.a * z.a, z.b * z.b);
		if (z_square.a + z_square.b > 4)
		{
			return ((double)i / mlx->max_iter);
		}
	}
	return (0);
}
