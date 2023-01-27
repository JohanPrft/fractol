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

void	hook_rgb(int keycode, t_mlx *mlx)
{
	if (keycode != R && keycode != G && keycode != B)
		return ;
	mlx->r = 0;
	mlx->g = 0;
	mlx->b = 0;
	if (keycode == R)
		mlx->r = 255;
	else if (keycode == G)
		mlx->g = 255;
	else if (keycode == B)
		mlx->b = 255;
}

int	key_hook(int keycode, t_mlx *mlx)
{
	(void)mlx;
	if (keycode == ESQ)
		free_and_exit(mlx);
	hook_moove(keycode, mlx);
	hook_zoom_iter(keycode, mlx);
	hook_rgb(keycode, mlx);
	draw_fract(mlx);
	return (1);
}

// for red cross
int	hook(t_mlx *mlx)
{
	free_and_exit(mlx);
	exit (0);
}

int	mouse_hook(int keycode, int x, int y, t_mlx *mlx)
{
	(void)x;
	(void)y;
	if (keycode == SCROLL_IN)
	{
		mult_mandel_size(mlx, 1.2);
		sub_iteration(mlx);
	}
	else if (keycode == SCROLL_OUT)
	{
		mult_mandel_size(mlx, 0.8);
		add_iteration(mlx);
	}
	draw_fract(mlx);
	return (1);
}
