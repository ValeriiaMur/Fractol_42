/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buttons.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmuradia <vmuradia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 16:16:07 by vmuradia          #+#    #+#             */
/*   Updated: 2018/12/05 18:43:23 by vmuradia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_zoom(int x, int y, t_data *data, double max_n)
{
	data->minReal = (x / data->zoom + data->minReal) - (x / (data->zoom * 1.01));
	data->min_i = (y / data->zoom + data->min_i) - (y / (data->zoom * 1.01));
	data->zoom *= 1.01;
	max_n++;
}

void	ft_dezoom(int x, int y, t_data *data, double max_n)
{
	data->minReal = (x / data->zoom + data->minReal)  - (x / (data->zoom / 1.01));
	data->min_i = (y / data->zoom + data->min_i) - (y / (data->zoom / 1.01));
	data->zoom /= 1.01;
	max_n--;
}

int		mouse_hook(int mousecode, int x, int y, t_data *data, int max_n)
{
	if (mousecode == 5 || mousecode == 2)
		ft_zoom(x, y, data, max_n);
	else if (mousecode == 4 || mousecode == 1)
		ft_dezoom(x, y, data, max_n);
	mlx_clear_window(data->mlx_ptr, data->win_ptr);
	mandelbrot(data);
	return (0);
}


int keys(int key, t_data *data)
{
	if (key == 53)
		exit(1);
	if (key == 18)
		data->color = 0x00ff00;
	else if (key == 19)
		data->color = 0xff69b4;
	else if (key == 20)
		data->color = 0xffdab9;
	mlx_clear_window(data->mlx_ptr, data->win_ptr);
	if (data->fractol == 0)
		mandelbrot(data);
	else if( data->fractol == 1)
		julia(data);
	return (0);
}
