/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jprofit <jprofit@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 15:44:00 by jprofit           #+#    #+#             */
/*   Updated: 2023/01/18 15:44:00 by jprofit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

t_point convert_point_repere(t_coord_syst win_size, t_coord_syst mandel, t_point point)
{
	point.a = point.a * ((mandel.max.a - mandel.min.a) / win_size.max.a) - mandel.max.a;
	point.b = point.b * ((mandel.max.b - mandel.min.b) / win_size.max.b) - mandel.max.b;
	return (point);
}

double divergent_speed (t_coord_syst win_size, t_coord_syst mandel_size, t_point p)
{
	int 	max_iter;
	int 	i;

	p = convert_point_repere(win_size, mandel_size, p);
	//printf("%f - %f\n", p.a, p.b);
	max_iter = 30;
	i = 0;
	while (++i < max_iter)
	{
		p = make_point(p.a * p.a - p.b * p.b, 2 * p.a * p.b); // ajouter c
		if (p.a * p.a + p.b * p.b > 4)
		{
			return ((double)i / max_iter);
		}
	}
	return (1);
}

void	mandelbrot(t_coord_syst win_size, t_coord_syst mandel_size, t_data	*img)
{
	int		i;
	int 	j;

	i = (int)win_size.max.b + 1;
	while (--i >= 0)
	{
		j = (int)win_size.max.a + 1;
		while (--j >= 0)
		{
			if (divergent_speed(win_size, mandel_size, make_point(j, i)) == 1)
			{
				mlx_pixel_put_img(img, j, i, 0xFFFFFF);
			}
			else
				mlx_pixel_put_img(img, j, i, 0x000000);
		}
	}
}