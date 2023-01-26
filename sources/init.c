/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jprofit <jprofit@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 15:42:00 by jprofit           #+#    #+#             */
/*   Updated: 2023/01/18 15:42:00 by jprofit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	init_window_size(t_mlx *mlx)
{
	mlx->win_size.min.a = 0;
	mlx->win_size.min.b = 0;
	mlx->win_size.max.a = 750;
	mlx->win_size.max.b = 750;
}

void	init_mandel_size(t_mlx *mlx)
{
	mlx->mandel_size.min.a = -1.8;
	mlx->mandel_size.min.b = -2;
	mlx->mandel_size.max.a = 2.2;
	mlx->mandel_size.max.b = 2;
}

void	mult_mandel_size(t_mlx *mlx, double x)
{
	mlx->mandel_size.min.a *= x;
	mlx->mandel_size.min.b *= x;
	mlx->mandel_size.max.a *= x;
	mlx->mandel_size.max.b *= x;
}

void	add_mandel_size_x(t_mlx *mlx, double x)
{
	mlx->offset.a += x;
	mlx->mandel_size.min.a += x;
	mlx->mandel_size.max.a += x;
}

void	add_mandel_size_y(t_mlx *mlx, double x)
{
	mlx->offset.b += x;
	mlx->mandel_size.min.b += x;
	mlx->mandel_size.max.b += x;
}

t_mlx	init_all(t_mlx *mlx)
{
	init_window_size(mlx);
	init_mandel_size(mlx);
	mlx->zoom_factor = 1;
	mlx->cursor_pos.a = 0;
	mlx->cursor_pos.b = 0;
	mlx->max_iter = 30;
	mlx->smooth = 1;
	mlx->mlx = mlx_init();
	mlx->offset.a = 0;
	mlx->offset.b = 0;
	return (*mlx);
}