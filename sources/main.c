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

#include "../slx/mlx/macos/mlx.h"
#include "../include/fractol.h"

int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;
	int		size;

	size = 500;
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, size, size, "Premiere pagination");
	mlx_loop(mlx_win);
	img.img = mlx_new_image(mlx, size, size);

}
