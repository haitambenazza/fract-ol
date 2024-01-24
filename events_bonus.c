/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbenazza <hbenazza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 08:47:26 by hbenazza          #+#    #+#             */
/*   Updated: 2024/01/23 19:49:55 by hbenazza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_close(t_data *data)
{
	mlx_destroy_image(data->mlx, data->img);
	mlx_destroy_window(data->mlx, data->window);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	write(1, "see ya :)\n", 10);
	exit(0);
	return (0);
}

int	keyboard(int key, t_data *data)
{
	if (key == XK_Escape)
		ft_close(data);
	else if (key == 65451)
	{
		data->iteration += 5;
		ft_putnbr_fd(data->iteration);
		write(1, " iterations \n", 13);
		ft_render(data->fractal, data);
	}
	else if (key == 65453)
	{
		data->iteration -= 5;
		ft_putnbr_fd(data->iteration);
		write(1, " iterations \n", 13);
		ft_render(data->fractal, data);
	}
	else
		k_color(key, data);
	return (0);
}

int	zoom(int button, int x, int y, t_data *data)
{
	(void)x;
	(void)y;
	if (button == 5)
	{
		data->zoom *= 0.95;
		ft_render(data->fractal, data);
	}
	if (button == 4)
	{
		data->zoom *= 1.2;
		ft_render(data->fractal, data);
	}
	return (0);
}

int	move(int key, t_data *data)
{
	if (key == 65363)
	{
		data->x += 0.2 * data->zoom;
		ft_render(data->fractal, data);
	}
	else if (key == 65362)
	{
		data->y -= 0.2 * data->zoom;
		ft_render(data->fractal, data);
	}
	else if (key == 65361)
	{
		data->x -= 0.2 * data->zoom;
		ft_render(data->fractal, data);
	}
	else if (key == 65364)
	{
		data->y += 0.2 * data->zoom;
		ft_render(data->fractal, data);
	}
	return (0);
}

void	managing(t_data *mlx)
{
	mlx_hook(mlx->window, 17, 0, &ft_close, mlx);
	mlx_hook(mlx->window, 3, (1L << 1), &keyboard, mlx);
	mlx_hook(mlx->window, 2, (1L << 0), &move, mlx);
	mlx_hook(mlx->window, 4, (1L << 2), &zoom, mlx);
}
