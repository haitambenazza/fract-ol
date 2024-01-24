/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbenazza <hbenazza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 09:36:55 by hbenazza          #+#    #+#             */
/*   Updated: 2024/01/23 20:21:25 by hbenazza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(int c, char **v)
{
	t_data	data;

	if (c < 2 || c > 4)
		handler();
	if (!(check_par(v, c)))
		exit(0);
	fract(&data, v);
	if (v[1][0] == '2')
		ft_render(v, &data);
	else if (v[1][0] == '1')
		ft_render(v, &data);
	mlx_loop(data.mlx);
	return (0);
}
