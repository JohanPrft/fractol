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

/*
typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;
*/

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

t_vector	*init_window_size()
{
	t_vector	*window_size;

	window_size = malloc(sizeof(*window_size));
	if (!window_size)
		exit (1);
	window_size->a = 1000;
	window_size->b = 1000;
	return (window_size);
}

int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;
	t_vector	*window_size;
	int		i;
	int 	j;

	window_size = init_window_size();
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, window_size->a, window_size->b, "🥵🥵🥵");
	img.img = mlx_new_image(mlx, window_size->a, window_size->b);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	i = window_size->b;
	while (i-- > 0)
	{
		j = window_size->a;
		while (j-- > 0)
		{
			my_mlx_pixel_put(&img, j, i, (0x00FF0000 + i));
		}
	}
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
	return (0);
}
