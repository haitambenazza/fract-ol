/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbenazza <hbenazza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 08:47:35 by hbenazza          #+#    #+#             */
/*   Updated: 2024/01/23 20:36:15 by hbenazza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	scale(double n, double min, double max, double old_max)
{
	return ((max - min) * (n - 0) / (old_max) + min);
}

unsigned int	argb(unsigned int a, unsigned int r, unsigned int g,
					unsigned int b)
{
	return (a << 24 | r << 16 | g << 8 | b);
}

void	put_pixel(t_data *data, int x, int y, unsigned int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bpp / 8));
	*(unsigned int *)dst = color;
}

void	colors(t_data *mlx)
{
	mlx->red = 0 + mlx->r_value;
	mlx->blue = 0 + mlx->b_value;
	mlx->green = 0 + mlx->g_value;
}

void	ft_render(char **str, t_data *mlx)
{
	(void)str;
	burning(mlx);
}
