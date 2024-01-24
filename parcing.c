/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbenazza <hbenazza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 11:18:33 by hbenazza          #+#    #+#             */
/*   Updated: 2024/01/23 20:47:50 by hbenazza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	handler(void)
{
	write(1, "invalid inputs!\n", 16);
	write(1, "USAGE: ./fractol <number of the fractal> \n", 42);
	write(1, "menu:\n1 ---mandelbrot\n2 ---julia\n", 34);
	write(1, "for julia specify the constant C <real> <imaginary>\n", 52);
	exit(0);
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

int	param(char *ch)
{
	int	i;
	int	c;

	i = 0;
	c = 0;
	while (ch[i])
	{
		if (ch[i] >= '0' && ch[i] <= '9')
			c++;
		i++;
	}
	if (c == 0)
		return (0);
	return (1);
}

int	isnum(char *str)
{
	int	len;
	int	c;

	len = 0;
	c = 0;
	while (str[len])
	{
		if ((str[len] >= '0' && str[len] <= '9') || str[len] == '-' || \
			str[len] == '.' || str[len] == '+')
			len++;
		else
			return (0);
	}
	len = 0;
	while (str[len])
	{
		if (str[len] == '-' || str[len] == '.' || str[len] == '+')
			c++;
		if (c > 2 || !param(str))
			return (0);
		len++;
	}
	return (1);
}

int	check_par(char **str, int c)
{
	int	len;

	len = 0;
	while (str[1][len])
		len++;
	if (len != 1)
		return (handler(), 0);
	if (str[1][0] < '1' || str[1][0] > '2')
		return (handler(), 0);
	if (str[1][0] == '2')
	{
		if (c != 4)
			handler();
		if (!(isnum(str[2])) || !(isnum(str[3])) || !(ft_strchr(str[2]) || \
		!(ft_strchr(str[3]))))
			return (handler(), 0);
	}
	else if (c > 2)
		handler();
	return (1);
}
