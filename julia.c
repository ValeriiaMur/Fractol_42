/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmuradia <vmuradia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 20:35:31 by vmuradia          #+#    #+#             */
/*   Updated: 2018/12/07 16:33:27 by vmuradia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	julia_init(t_data *data)
{
	data->width = 1000;
	data->height = 1000;
	data->color = 0x006600;
	data->zoom = 1;
	data->cRe = -0.7;
	data->cIm = 0.27015;
	data->newRe = 0;
	data->newIm = 0;
	data->oldRe = 0;
	data->oldIm = 0;
	data->max_n = 200;
	julia(data);
}

int		julia_n(t_data *data)
{
	int i;

	i = 0;
	while (i < data->max_n && data->newRe * data->newRe +
		data->newIm * data->newIm < 4)
	{
		data->oldRe = data->newRe;
		data->oldIm = data->newIm;
		data->newRe = data->oldRe * data->oldRe - data->oldIm *
			data->oldIm + data->cRe;
		data->newIm = 2 * data->oldRe * data->oldIm + data->cIm;
		i++;
	}
	return (i);
}

void	julia(t_data *data)
{
	int n;
	int x;
	int y;

	n = 0;
	x = 100;
	y = 100;
	mlx_string_put(data->mlx_ptr, data->win_ptr, 500, 40, 0xffffff, "Julia");
	while (y < data->height)
	{
		while (x < data->width)
		{
			data->newRe = 1.5 * (x - data->width / 2) / (0.3 * data->zoom *
				data->width);
			data->newIm = (y - data->height / 2) / (0.3 * data->zoom *
				data->height);
			n = julia_n(data);
			if (n < data->max_n)
				mlx_pixel_put(data->mlx_ptr, data->win_ptr, x, y,
					(data->color * n / 100));
			x++;
		}
		y++;
		x = 100;
	}
}
