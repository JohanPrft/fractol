/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jprofit <jprofit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 15:47:00 by jprofit           #+#    #+#             */
/*   Updated: 2023/01/16 11:28:10 by jprofit          ###   ########.fr       */
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

void	mlx_pixel_put_img(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void	mlx(void)
{
	void			*mlx;
	void			*mlx_win;
	t_coord_syst	win_size;
	t_coord_syst	mandel_size;
	t_data			img;

	win_size = init_window_size();
	mandel_size = init_mandel_size();
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, (int)win_size.max.a, (int)win_size.max.b, "🥵🥵🥵");
	img = create_image(mlx, win_size);
	modif_image(win_size, &img);
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mandelbrot(win_size, mandel_size, &img);
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
}

int	main(int argc, char **argv)
{
	(void)argc;
	(void)argv;
	mlx();
	return (0);
}
