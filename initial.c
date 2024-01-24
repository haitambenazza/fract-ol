/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initial.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbenazza <hbenazza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 20:34:14 by hbenazza          #+#    #+#             */
/*   Updated: 2024/01/23 17:03:18 by hbenazza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init(t_data *mlx, char **str)
{
	mlx->red = 0;
	mlx->blue = 0;
	mlx->green = 0;
	mlx->r_value = 0;
	mlx->g_value = 0;
	mlx->b_value = 0;
	mlx->iteration = 30;
	mlx->max = 2;
	mlx->min = -2;
	mlx->fractal = str;
	mlx->x = 0;
	mlx->y = 0;
	mlx->zoom = 1;
}

void	destroyer(t_data *mlx)
{
	perror("an error occured\n");
	mlx_destroy_image(mlx->mlx, mlx->img);
	mlx_destroy_display(mlx->mlx);
	mlx_destroy_window(mlx->mlx, mlx->window);
	exit(0);
}

void	fract(t_data *mlx, char **str)
{
	mlx->mlx = mlx_init();
	if (!mlx->mlx)
		destroyer(mlx);
	mlx->window = mlx_new_window(mlx->mlx, WIDTH, HEIGHT, "fractal");
	if (!mlx->window)
		destroyer(mlx);
	mlx->img = mlx_new_image(mlx->mlx, WIDTH, HEIGHT);
	if (!mlx->img)
		destroyer(mlx);
	mlx->addr = mlx_get_data_addr(mlx->img, &mlx->bpp, &mlx->line_length,
			&mlx->indean);
	if (!mlx->addr)
		destroyer(mlx);
	init(mlx, str);
	managing(mlx);
}
