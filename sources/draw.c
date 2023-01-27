/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jprofit <jprofit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 15:44:00 by jprofit           #+#    #+#             */
/*   Updated: 2023/01/24 09:44:55 by jprofit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

t_point	convert_point_repere(t_mlx *mlx, t_point point)
{
	point.a = point.a * ((mlx->mandel_size.max.a - mlx->mandel_size.min.a)
			/ mlx->win_size.max.a) - mlx->mandel_size.max.a;
	point.b = point.b * ((mlx->mandel_size.max.b - mlx->mandel_size.min.b)
			/ mlx->win_size.max.b) - mlx->mandel_size.max.b;
	point.a -= mlx->offset.a;
	point.b -= mlx->offset.b;
	return (point);
}

// offset to know where to write in memory
void	mlx_pixel_put_img(t_data *img, int x, int y, int color)
{
	char	*dst;
	int		offset;

	offset = y * img->line_length + x * (img->bits_per_pixel / 8);
	dst = img->addr + offset;
	*(unsigned int *)dst = color;
}

void	draw_fract(t_mlx *mlx)
{
	int		i;
	int		j;
	double	div;

	i = (int)mlx->win_size.max.b;
	while (--i >= 0)
	{
		j = (int)mlx->win_size.max.a;
		while (--j >= 0)
		{
			div = (*mlx->divergent_speed)(mlx, make_point(j, i));
			mlx_pixel_put_img(&mlx->img, j, i, \
			create_trgb(0, div * mlx->r, div * mlx->g, div * mlx->b));
		}
	}
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img.img, 0, 0);
}
