/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imac <imac@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 15:47:00 by jprofit           #+#    #+#             */
/*   Updated: 2023/01/23 10:28:20 by imac             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

t_point	make_point(double a, double b)
{
	t_point	point;

	point.a = a;
	point.b = b;
	return (point);
}

void free_and_exit(t_mlx *mlx)
{
	//mlx_destroy_image(mlx->mlx, &mlx->img);
	mlx_destroy_window(mlx->mlx, mlx->win);
	exit(0);
}

int key_hook(int keycode, t_mlx *mlx)
{
	(void)mlx;
	if (keycode == ESQ)
		free_and_exit(mlx);
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
	//printf ("relative	: x = %f, y = %f\n", mlx->cursor_pos.a, mlx->cursor_pos.b);
	//printf ("reel		: x = %d, y = %d\n", x, y);
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
	draw_fract(mlx);
	return (1);
}

int	arg_management(int argc, char **argv, t_mlx *mlx)
{
	if (argc < 2 || argc > 3)
		return (0);
	if (argv[1][0] == 'm' && argv[1][1] == '\0')
	{
		if (argc > 2)
			return (0);
		mlx->divergent_speed = mandelbrot;
	}
	else if (argv[1][0] == 'j' && argv[1][1] == '\0')
	{
		if (argc == 3 && ((argv[2][0] < '0' || argv[2][0] > '4') || argv[2][1] != '\0'))
			return (0);
		else if (argc == 3)
			mlx->fract_arg = argv[2][0];
		mlx->divergent_speed = julia;
	}
	else if (argv[1][0] == 'b' && argv[1][1] == '\0')
	{
		if (argc > 2)
			return (0);
		mlx->divergent_speed = burning_ship;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_mlx	mlx;

	(void)argc;
	(void)argv;

	if (!arg_management(argc, argv, &mlx))
	{
		write(2, "Please input \"M\" for Mandelbrot or \"J\" for Julia\n", 49);
		return (0);
	}
	init_all(&mlx);
	mlx.win = mlx_new_window(mlx.mlx, (int)mlx.win_size.max.a, (int)mlx.win_size.max.b, "🥵🥵🥵");
	mlx.img.img = mlx_new_image(mlx.mlx, (int)mlx.win_size.max.a, (int)mlx.win_size.max.b);
	mlx.img.addr = mlx_get_data_addr(mlx.img.img, &mlx.img.bits_per_pixel, &mlx.img.line_length, &mlx.img.endian);

	draw_fract(&mlx);

	mlx_key_hook(mlx.win, key_hook, &mlx);
	mlx_mouse_hook(mlx.win, mouse_hook, &mlx);
	mlx_hook(mlx.win, 17, 0, hook, &mlx);
	mlx_loop(mlx.mlx);
}
