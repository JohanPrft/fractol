/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imac <imac@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 15:47:00 by jprofit           #+#    #+#             */
/*   Updated: 2023/02/03 12:43:29 by jprofit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	explicative_instruction(void)
{
	int	i;

	i = write(1, "Hey !\nYou can choose your fractal at startup : \n", 48);
	i = write(1, "m for Mandelbrot, j for Julia or b for ship.\n", 46);
	i = write(1, "Presets available for Julia (add 0 to 4).\n", 43);
	if (i)
		return ;
}

int	main(int argc, char **argv)
{
	t_mlx	mlx;

	explicative_instruction();
	if (!arg_management(argc, argv, &mlx))
	{
		if (write(2, "\n!! Please input a correct parameter !!\n", 40))
			return (0);
	}
	init_all(&mlx);
	mlx.win = mlx_new_window(mlx.mlx, (int)mlx.win_size.max.a, \
	(int)mlx.win_size.max.b, "fractol");
	mlx.img.img = mlx_new_image(mlx.mlx, (int)mlx.win_size.max.a, \
	(int)mlx.win_size.max.b);
	mlx.img.addr = mlx_get_data_addr(mlx.img.img, &mlx.img.bits_per_pixel, \
	&mlx.img.line_length, &mlx.img.endian);
	draw_fract(&mlx);
	mlx_key_hook(mlx.win, key_hook, &mlx);
	mlx_mouse_hook(mlx.win, mouse_hook, &mlx);
	mlx_hook(mlx.win, 17, 0, hook, &mlx);
	mlx_loop(mlx.mlx);
}
