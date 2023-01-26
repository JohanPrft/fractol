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
