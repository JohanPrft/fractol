/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jprofit <jprofit@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 09:28:00 by jprofit           #+#    #+#             */
/*   Updated: 2023/01/26 09:28:00 by jprofit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int key_hook(int keycode, t_mlx *mlx)
{
	(void)mlx;
	printf ("keycode = %i\n", keycode);
	if (keycode == ESQ)
		free_and_exit(mlx);
	if (keycode == UP || keycode == W)
		add_mandel_size_y(mlx, 0.1 * (mlx->mandel_size.max.b - mlx->mandel_size.min.b));
	if (keycode == DOWN || keycode == S)
		add_mandel_size_y(mlx, -0.1 * (mlx->mandel_size.max.b - mlx->mandel_size.min.b));
	if (keycode == RIGHT || keycode == D)
		add_mandel_size_x(mlx, -0.1 * (mlx->mandel_size.max.a - mlx->mandel_size.min.a));
	if (keycode == LEFT || keycode == A)
		add_mandel_size_x(mlx, 0.1 * (mlx->mandel_size.max.a - mlx->mandel_size.min.a));
	draw_fract(mlx);
	return (1);
}

int hook(t_mlx *mlx)
{
	free_and_exit(mlx);
	exit (0);
}

int mouse_hook(int keycode, int x, int y, t_mlx *mlx)
{
	(void)x;
	(void)y;
	if (keycode == SCROLL_IN)
	{
		mlx->cursor_pos = convert_point_repere(mlx, make_point(x, y));
		mult_mandel_size(mlx, 1.2);
		mlx->max_iter--;
	}
	else if (keycode == SCROLL_OUT)
	{
		mlx->cursor_pos = convert_point_repere(mlx, make_point(x, y));
		mult_mandel_size(mlx, 0.8);
		mlx->max_iter++;
	}
	//compute_mandel_size(mlx);
	draw_fract(mlx);
	return (1);
}