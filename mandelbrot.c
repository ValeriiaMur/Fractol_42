/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmuradia <vmuradia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 16:05:03 by vmuradia          #+#    #+#             */
/*   Updated: 2018/12/07 16:02:16 by vmuradia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	mandelbrot_init(t_data *data)
{
	data->width = 1000;
	data->height = 1000;
	data->minReal = -2.05;
	data->maxReal = 1.2;
	data->min_i = -1.3;
	data->max_i = 1.2;
	data->color = 0xd7afd7;
	data->zoom = 200;
	data->max_n = 200;
	mandelbrot(data);
}

int		find_n(double cr, double ci, double max_n)
{
	int			i;
	double		zr;
	double		zi;
	double		temp;

	i = 0;
	zr = 0;
	zi = 0;
	while (i < max_n && zr * zr + zi * zi < 4.0)
	{
		temp = zr * zr - zi * zi + cr;
		zi = 2.0 * zr * zi + ci;
		zr = temp;
		i++;
	}
	return (i);
}

void	mandelbrot(t_data *data)
{
	int		x;
	int		y;
	int		n;

	x = 100;
	y = 100;
	mlx_string_put(data->mlx_ptr, data->win_ptr, 500, 40, 0xffffff,
		"Mandelbrot Set");
	while (x < data->width)
	{
		while (y < data->height)
		{
			data->cRe = find_real(x, data);
			data->cIm = find_imaginary(y, data);
			n = find_n(data->cRe, data->cIm, data->max_n);
			if (n == data->max_n)
				mlx_pixel_put(data->mlx_ptr, data->win_ptr, x, y, 0x000000);
			else
				mlx_pixel_put(data->mlx_ptr, data->win_ptr, x, y,
					(data->color * n / 100));
			y++;
		}
		x++;
		y = 100;
	}
}

double	find_real(int x, t_data *data)
{
	double	range;

	range = data->maxReal - data->minReal;
	return (x * (range / data->width) + data->minReal);
}

double	find_imaginary(int y, t_data *data)
{
	double range;

	range = data->max_i - data->min_i;
	return (y * (range / data->height) + data->min_i);
}
