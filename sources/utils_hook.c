/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_hook.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jprofit <jprofit@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 14:12:00 by jprofit           #+#    #+#             */
/*   Updated: 2023/01/27 14:12:00 by jprofit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	add_iteration(t_mlx *mlx)
{
	if (mlx->max_iter < 150)
		mlx->max_iter++;
	else
		mlx->max_iter = 149;
}

void	sub_iteration(t_mlx *mlx)
{
	if (mlx->max_iter > 20)
		mlx->max_iter--;
	else
		mlx->max_iter = 19;
}

void	mult_mandel_size(t_mlx *mlx, double x)
{
	mlx->mandel_size.min.a *= x;
	mlx->mandel_size.min.b *= x;
	mlx->mandel_size.max.a *= x;
	mlx->mandel_size.max.b *= x;
}

void	hook_moove(int keycode, t_mlx *mlx)
{
	if (keycode == UP || keycode == W)
		mlx->offset.b += 0.05 * \
		(mlx->mandel_size.max.b - mlx->mandel_size.min.b);
	else if (keycode == DOWN || keycode == S)
		mlx->offset.b += -0.05 * \
		(mlx->mandel_size.max.b - mlx->mandel_size.min.b);
	else if (keycode == RIGHT || keycode == D)
		mlx->offset.a += -0.05 * \
		(mlx->mandel_size.max.a - mlx->mandel_size.min.a);
	else if (keycode == LEFT || keycode == A)
		mlx->offset.a += \
		0.05 * (mlx->mandel_size.max.a - mlx->mandel_size.min.a);
}

void	hook_zoom_iter(int keycode, t_mlx *mlx)
{
	if (keycode == O)
	{
		mult_mandel_size(mlx, 1.2);
		sub_iteration(mlx);
	}
	else if (keycode == P)
	{
		mult_mandel_size(mlx, 0.8);
		add_iteration(mlx);
	}
	else if (keycode == PLUS)
		add_iteration(mlx);
	else if (keycode == MINUS)
		sub_iteration(mlx);
}
