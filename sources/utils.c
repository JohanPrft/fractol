/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jprofit <jprofit@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 09:29:00 by jprofit           #+#    #+#             */
/*   Updated: 2023/01/26 09:29:00 by jprofit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

t_point	make_point(double a, double b)
{
	t_point	point;

	point.a = a;
	point.b = b;
	return (point);
}

int	set_fractale(t_mlx *mlx, char c, char preset)
{
	if (c == 'm')
		mlx->divergent_speed = mandelbrot;
	else if (c == 'j')
	{
		mlx->fract_arg = preset;
		mlx->divergent_speed = julia;
	}
	else if (c == 'b')
		mlx->divergent_speed = burning_ship;
	return (1);
}

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	free_and_exit(t_mlx *mlx)
{
	mlx_destroy_image(mlx->mlx, mlx->img.img);
	mlx_destroy_window(mlx->mlx, mlx->win);
	exit(0);
}
