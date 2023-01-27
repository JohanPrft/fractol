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

int	arg_management(int argc, char **argv, t_mlx *mlx)
{
	int		len;
	char	c;
	char	preset;

	if (argc != 2)
		return (0);
	len = ft_strlen(argv[1]);
	if (len < 1 || len > 2)
		return (0);
	c = argv[1][0];
	if (c != 'm' && c != 'j' && c != 'b')
		return (0);
	preset = 0;
	if (len == 2)
	{
		if (c != 'j')
			return (0);
		preset = argv[1][1];
		if (preset < '0' || preset > '4')
			return (0);
	}
	set_fractale(mlx, c, preset);
	return (1);
}

void	init_window_size(t_mlx *mlx)
{
	mlx->win_size.min.a = 0;
	mlx->win_size.min.b = 0;
	mlx->win_size.max.a = 750;
	mlx->win_size.max.b = 750;
}

void	init_mandel_size(t_mlx *mlx)
{
	mlx->mandel_size.min.a = -1.8;
	mlx->mandel_size.min.b = -2;
	mlx->mandel_size.max.a = 2.2;
	mlx->mandel_size.max.b = 2;
}

t_mlx	init_all(t_mlx *mlx)
{
	init_window_size(mlx);
	init_mandel_size(mlx);
	mlx->cursor_pos.a = 0;
	mlx->cursor_pos.b = 0;
	mlx->max_iter = 30;
	mlx->mlx = mlx_init();
	mlx->offset.a = 0;
	mlx->offset.b = 0;
	mlx->r = 255;
	mlx->g = 0;
	mlx->b = 0;
	return (*mlx);
}
