/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbenazza <hbenazza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 10:38:58 by hbenazza          #+#    #+#             */
/*   Updated: 2024/01/23 20:51:00 by hbenazza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_putchar_fd(char c)
{
	write(1, &c, 1);
}

int	ft_strchr(char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		if (s[i] >= '0' || s[i] <= '9')
			return (1);
		i++;
	}
	return (0);
}

void	ft_putnbr_fd(int n)
{
	if (n < 0)
	{
		ft_putchar_fd('-');
		n = -(n);
	}
	if (n >= 10)
	{
		ft_putnbr_fd(n / 10);
		ft_putnbr_fd(n % 10);
	}
	else
		ft_putchar_fd(n +48);
}

int	k_color(int key, t_data *mlx)
{
	if (key == XK_a)
		return (mlx->r_value += 15, ft_render(mlx->fractal, mlx), 0);
	else if (key == XK_s)
		return (mlx->g_value += 15, ft_render(mlx->fractal, mlx), 0);
	else if (key == XK_d)
		return (mlx->b_value += 15, ft_render(mlx->fractal, mlx), 0);
	if (key == XK_q)
		return (mlx->r_value -= 15, ft_render(mlx->fractal, mlx), 0);
	else if (key == XK_w)
		return (mlx->g_value -= 15, ft_render(mlx->fractal, mlx), 0);
	else if (key == XK_e)
		return (mlx->b_value -= 15, ft_render(mlx->fractal, mlx), 0);
	return (0);
}
