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

t_coord_syst	init_window_size()
{
	t_coord_syst	window_size;

	window_size.min.a = 0;
	window_size.min.b = 0;
	window_size.max.a = 1000;
	window_size.max.b = 1000;
	return (window_size);
}

t_coord_syst	init_mandel_size(void)
{
	t_coord_syst	mandelbrot;

	mandelbrot.min.a = -2;
	mandelbrot.min.b = -2;
	mandelbrot.max.a = 2;
	mandelbrot.max.b = 2;
	return (mandelbrot);
	/*
	const double CxMin=-2.5;
	const double CxMax=1.5;
	const double CyMin=-2.0;
	const double CyMax=2.0;
	*/
}

t_data	create_image(void *mlx, t_coord_syst win_size)
{
	t_data	img;

	img.img = mlx_new_image(mlx, (int)win_size.max.a, (int)win_size.max.b);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	return (img);
}

void	modif_image(t_coord_syst win_size, t_data	*img)
{
	int		i;
	int 	j;

	i = (int)win_size.max.b;
	while (i-- > 0)
	{
		j = (int)win_size.max.a;
		while (j-- > 0)
		{
				mlx_pixel_put_img(img, j, i, 0x000000 + i/4);
		}
	}
}