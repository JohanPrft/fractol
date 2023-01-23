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

	mandelbrot.min.a = -1.8;
	mandelbrot.min.b = -2;
	mandelbrot.max.a = 2.2;
	mandelbrot.max.b = 2;
	return (mandelbrot);
	/*
	const double CxMin=-2.5;
	const double CxMax=1.5;
	const double CyMin=-2.0;
	const double CyMax=2.0;
	*/
}

t_mlx	init_all(void)
{
	t_mlx mlx;

	mlx.win_size = init_window_size();
	mlx.mandel_size = init_mandel_size();
	mlx.zoom_factor = 1;
	mlx.cursor_pos.a = 0;
	mlx.cursor_pos.b = 0;
	mlx.mlx = mlx_init();
	return (mlx);
}

//t_data	create_image(void *mlx, t_coord_syst win_size)
//{
//	t_data	img;
//
//	return (img);
//}

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