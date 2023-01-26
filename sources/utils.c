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

t_point	make_point(double a, double b)
{
	t_point	point;

	point.a = a;
	point.b = b;
	return (point);
}

void	free_and_exit(t_mlx *mlx)
{
	mlx_destroy_image(mlx->mlx, mlx->img.img);
	mlx_destroy_window(mlx->mlx, mlx->win);
	exit(0);
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