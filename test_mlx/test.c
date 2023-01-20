/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jprofit <jprofit@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 10:59:00 by jprofit           #+#    #+#             */
/*   Updated: 2023/01/20 10:59:00 by jprofit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

typedef struct	s_vars {
	void	*mlx;
	void	*win;
}				t_vars;

int key_hook(int keycode,t_vars *vars)
{
	(void)vars;
	if (keycode == 53)
		exit (0);
	printf("%i\n", keycode);
	return (keycode);
}

int	main(void)
{
	struct s_vars	vars;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 1000, 1000, "🤥");

	mlx_key_hook(vars.win, key_hook, &vars);
	mlx_loop(vars.mlx);
	return (0);
}