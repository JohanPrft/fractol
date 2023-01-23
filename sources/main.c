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

int key_hook(int keycode)
{
	if (keycode == 53)
		exit (0);

	return (1);
}

int hook(t_mlx mlx)
{
	(void)mlx;
	//mlx_destroy_image(&mlx.mlx, &mlx.img);
	//mlx_destroy_window(&mlx.mlx, &mlx.win);
	exit (0);
}

int mouse_hook(int keycode, t_mlx mlx)
{
	(void)mlx;
	if (keycode == 4)
	{
		printf("up \n");
	}
	else if (keycode == 5)
		printf("down \n");
	return (1);
}

int	render_next_frame(t_mlx mlx)
{
	(void)mlx;
	// mlx_destroy_image(&mlx.mlx, &mlx.img);
	// mandelbrot(mlx.win_size, mlx.mandel_size, &mlx.img);
	// mlx_put_image_to_window(mlx.mlx, mlx.win, mlx.img.img, 0, 0);
	return (0);
}

void	mlx(void)
{
	t_mlx			mlx;

	mlx.win_size = init_window_size();
	mlx.mandel_size = init_mandel_size();
	mlx.mlx = mlx_init();

	mlx.win = mlx_new_window(mlx.mlx, (int)mlx.win_size.max.a, (int)mlx.win_size.max.b, "🥵🥵🥵");
	mlx.img = create_image(mlx.mlx, mlx.win_size);
	mlx_put_image_to_window(mlx.mlx, mlx.win, mlx.img.img, 0, 0); // crash si pas de premier affichage de rien
	mandelbrot(mlx.win_size, mlx.mandel_size, &mlx.img);
	mlx_put_image_to_window(mlx.mlx, mlx.win, mlx.img.img, 0, 0);

	mlx_key_hook(mlx.win, key_hook, NULL);
	mlx_mouse_hook(mlx.win, mouse_hook, &mlx);
	mlx_loop_hook(mlx.mlx, render_next_frame, &mlx);
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
