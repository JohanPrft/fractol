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

void	mlx_pixel_put_img(t_data *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int key_hook(int keycode, t_mlx *mlx)
{
	(void)mlx;
	if (keycode == 53)
		exit (0);
	else if (keycode == 3) // key = F
	{
		printf("f\n");
		mandelbrot(mlx);
		mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img.img, 0, 0);
	}
	return (1);
}

int hook(t_mlx *mlx)
{
	(void)mlx;
	exit (0);
}

int mouse_hook(int keycode, int x, int y, t_mlx *mlx)
{
	(void)mlx;
	mlx->cursor_pos = convert_point_repere(mlx, make_point(x, y));
	printf("x = %f, y = %f\n", mlx->cursor_pos.a, mlx->cursor_pos.b);

	if (keycode == 4)
		mlx->zoom_factor *= 1.1;
	else if (keycode == 5)
		mlx->zoom_factor *= 0.9;
	mandelbrot(mlx);
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img.img, 0, 0);
	return (1);
}

int	render_next_frame(t_mlx *mlx)
{
	(void)mlx;
	return (0);
}

void	mlx(void)
{
	t_mlx	mlx;

	mlx = init_all();
	mlx.win = mlx_new_window(mlx.mlx, (int)mlx.win_size.max.a, (int)mlx.win_size.max.b, "🥵🥵🥵");
	mlx.img.img = mlx_new_image(mlx.mlx, (int)mlx.win_size.max.a, (int)mlx.win_size.max.b);
	mlx.img.addr = mlx_get_data_addr(mlx.img.img, &mlx.img.bits_per_pixel, &mlx.img.line_length, &mlx.img.endian);

	mlx_key_hook(mlx.win, key_hook, &mlx);
	mlx_mouse_hook(mlx.win, mouse_hook, &mlx);
//	mlx_loop_hook(mlx.mlx, render_next_frame, &mlx);
	mlx_hook(mlx.win, 17, 0, hook, &mlx);

	mlx_loop(mlx.mlx);
}

int	main(int argc, char **argv)
{
	(void)argc;
	(void)argv;
	mlx();
	return (0);
}
