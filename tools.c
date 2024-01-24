/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbenazza <hbenazza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 10:38:58 by hbenazza          #+#    #+#             */
/*   Updated: 2024/01/21 21:16:25 by hbenazza         ###   ########.fr       */
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

int	ft_atoi(const char *str)
{
	int			sign;
	long long	number;
	size_t		i;

	sign = 1;
	number = 0;
	i = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		number = number * 10 + (str[i] - '0');
		i++;
	}
	return (number * sign);
}

double	ft_atod(const char *str)
{
	double	n;
	size_t	i;
	double	n1;
	double	it;

	it = 10.0;
	i = 0;
	n = 0;
	n1 = (double)ft_atoi(str);
	while (str[i] != '.')
		i++;
	if (str[i] == '.')
		i++;
	while (str[i] >= '0' && str[i] <= '9' && str[i])
	{
		n += (double)(str[i] - 48) / it;
		i++;
		it *= 10;
	}
	if (str[0] == '-')
		n *= -1;
	return (n + n1);
}
