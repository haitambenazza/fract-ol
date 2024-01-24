/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burning_ship.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbenazza <hbenazza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 21:09:27 by hbenazza          #+#    #+#             */
/*   Updated: 2024/01/22 21:13:13 by hbenazza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	burning_eq(int x, int y, t_data *m)
{
	int			it;
	t_complex	tmp;
	t_complex	z;
	t_complex	cte;

	cte.i = scale((double)y, m->min, m->max, HEIGHT) * m->zoom + m->y;
	cte.r = scale((double)x, m->min, m->max, WIDTH) * m->zoom + m->x;
	z.i = 0;
	z.r = 0;
	it = 0;
	colors(m);
	while (it++ <= m->iteration)
	{
		tmp.r = (z.r);
		z.r = (fabs(z.r) * fabs(z.r) - fabs(z.i) * fabs(z.i)) + cte.r;
		z.i = (2 * fabs(tmp.r * z.i)) + cte.i;
		if (fabs((z.r) * (z.r)) + fabs((z.i) * (z.i)) >= 4)
			return (put_pixel(m, x, y,
					argb(0, m->red, m->green, m->blue)), 0);
		m->red += 10;
		m->blue += 10;
		m->green += 10;
	}
	return (put_pixel(m, x, y, 0x0ffffff), 1);
}

void	burning(t_data *data)
{
	int		y;
	int		x;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			burning_eq(x, y, data);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(data->mlx, data->window, data->img, 0, 0);
}
