/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbenazza <hbenazza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 21:55:09 by hbenazza          #+#    #+#             */
/*   Updated: 2024/01/22 15:26:31 by hbenazza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	r_julia(t_complex c, int x, int y, t_data *data)
{
	int				it;
	t_complex		tmp;
	t_complex		z;
	t_complex		cte;

	cte.i = c.i;
	cte.r = c.r;
	z.i = scale((double)y, data->min, data->max, HEIGHT) * data->zoom + data->y;
	z.r = scale((double)x, data->min, data->max, WIDTH) * data->zoom + data->x;
	it = 0;
	colors(data);
	while (it < data->iteration)
	{
		tmp.r = z.r;
		z.r = ((z.r) * (z.r) - (z.i) * (z.i)) + cte.r;
		z.i = (2 * tmp.r * z.i) + cte.i;
		if ((z.r) * (z.r) + (z.i) * (z.i) >= 4)
			return (put_pixel(data, x, y,
					argb(0, data->red, data->green, data->blue)), 0);
		it++;
		data->red += 10;
		data->blue += 10;
		data->green += 10;
	}
	return (put_pixel(data, x, y, argb(0, 255, 255, 255)), 1);
}

void	julia(double r, double i, t_data *data)
{
	int			y;
	int			x;
	t_complex	c;

	y = 0;
	c.i = i;
	c.r = r;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			r_julia(c, x, y, data);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(data->mlx, data->window, data->img, 0, 0);
}
