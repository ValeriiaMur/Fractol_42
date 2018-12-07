/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buttons.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmuradia <vmuradia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 16:16:07 by vmuradia          #+#    #+#             */
/*   Updated: 2018/12/06 20:23:40 by vmuradia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_zoom(int x, int y, t_data *data)
{
	data->minReal = (x / data->zoom + data->minReal) - (x / (data->zoom * 1.01));
	data->min_i = (y / data->zoom + data->min_i) - (y / (data->zoom * 1.01));
	data->zoom *= 1.01;
	data->max_n++;
}

void	ft_dezoom(int x, int y, t_data *data)
{
	data->minReal = (x / data->zoom + data->minReal)  - (x / (data->zoom / 1.01));
	data->min_i = (y / data->zoom + data->min_i) - (y / (data->zoom / 1.01));
	data->zoom /= 1.01;
	data->max_n--;
}

int mouse_hook(int mousecode, int x, int y, t_data *data)
{
	(void)x;
	(void)y;
	if (data->fractol == 0)
	{
		if (mousecode == 5 || mousecode == 2)
			ft_zoom(x, y, data);
		else if (mousecode == 4 || mousecode == 1)
			ft_dezoom(x, y, data);
		mlx_clear_window(data->mlx_ptr, data->win_ptr);
	 	mandelbrot(data);
	}
	else if (data->fractol == 1)
	{
		if (mousecode == 2 || mousecode == 5)
		{
	 		data->zoom *= 2.01;
			data->max_n++;
		}
		else if (mousecode == 4 || mousecode == 1)
		{
		 	data->zoom /= 2.01;
			data->max_n--;
		}
	 	mlx_clear_window(data->mlx_ptr, data->win_ptr);
	 	julia(data);
	}
	return (0);
}

void	put_text(t_data *data)
{
	char	*text;
	char	*nb;

	nb = ft_itoa(data->max_n);
	text = ft_strjoin("iterations : ", nb);
	mlx_string_put(data->mlx_ptr, data->win_ptr, 10, 10, 0xFFFFFF, text);
	ft_strdel(&text);
	ft_strdel(&nb);
}

int keys(int key, t_data *data)
{
	if (key == 53)
		exit(1);
	else if (key == 18)
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

int		mouse_julia(int x, int y, t_data *data)
{
	if (data->fractol == 1 && data->julia_mouse == 1)
	{
		data->cRe = x * 2;
		data->cIm = y * 2 - 800;
		mlx_clear_window(data->mlx_ptr, data->win_ptr);
		julia(data);
	}
	return (0);
}
