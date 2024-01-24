/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbenazza <hbenazza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 16:21:43 by hbenazza          #+#    #+#             */
/*   Updated: 2024/01/23 20:48:06 by hbenazza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <mlx.h>
# include <math.h>
# include <unistd.h>
# include <X11/keysym.h>
# include <stdlib.h>
# include <stdio.h>

# define WIDTH 1000
# define HEIGHT 1000

typedef struct s_data
{
	void			*img;
	void			*addr;
	void			*mlx;
	void			*window;
	int				bpp;
	int				line_length;
	int				offset;
	int				indean;
	double			min;
	double			max;
	int				iteration;
	unsigned int	red;
	unsigned int	blue;
	unsigned int	green;
	char			**fractal;
	double			x;
	double			y;
	double			zoom;
	unsigned int	r_value;
	unsigned int	b_value;
	unsigned int	g_value;
}	t_data;

typedef struct complex
{
	double	i;
	double	r;
}	t_complex;

double			scale(double n, double min, double max, double old_max);
void			put_pixel(t_data *data, int x, int y, unsigned int color);
unsigned int	argb(unsigned int a, unsigned int r, unsigned int g,
					unsigned int b);
void			render_img(t_data *data);
int				ft_close(t_data *data);
int				esc(int key, t_data *data);
void			mandelbrot(t_data *data);
int				mandelbrot_eq(int x, int y, t_data *data);
int				isnum(char *str);
void			handler(void);
int				check_par(char **str, int c);
int				ft_atoi(const char *str);
double			ft_atod(const char *str);
void			julia(double r, double i, t_data *data);
int				r_julia(t_complex c, int x, int y, t_data *data);
void			managing(t_data *mlx);
void			init(t_data *mlx, char **str);
void			fract(t_data *mlx, char **str);
void			ft_render(char **str, t_data *mlx);
void			destroyer(t_data *mlx);
int				ft_strchr(char *s);
void			ft_putchar_fd(char c);
void			ft_putnbr_fd(int n);
void			colors(t_data *mlx);
int				k_color(int key, t_data *mlx);
int				burning_eq(int x, int y, t_data *m);
void			burning(t_data *data);
int				param(char *ch);

#endif
