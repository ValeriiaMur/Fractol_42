/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmuradia <vmuradia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 20:35:31 by vmuradia          #+#    #+#             */
/*   Updated: 2018/12/05 11:49:59 by vmuradia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"


void	julia_init(t_data *data)
{
	data->width = 1000;
	data->height = 1000;
	data->color = 0xd7afd7;
	data->zoom = 1;
	data->cRe = -0.7;
	data->cIm = 0.27015;
	data->moveX = 0;
	data->moveY = 0;
	data->newRe = 0;
	data->newIm = 0;
	data->oldRe = 0;
	data->oldIm = 0;
	julia(data);
}

void zoom_julia(t_data *data)
{
	data->zoom = data->zoom * 1.2;
	julia(data);
}

void	julia(t_data *data)
{
	int max_n;
	int n;

	mlx_string_put(data->mlx_ptr, data->win_ptr, 500, 40, 0xffffff, "Julia Set");
	max_n = 100;
	for (int y = 100; y < data->height; y++)
	{
		for (int x = 100; x < data->width; x++)
		{
			data->newRe = 1.5 * (x - data->width / 2) / (0.3 * data->zoom * data->width) + data->moveX;
  			data->newIm = (y - data->height / 2) / (0.3 * data->zoom * data->height) + data->moveY;

			n = 0;
			for (n = 0; n < max_n; n++)
			{
				data->oldRe = data->newRe;
      			data->oldIm = data->newIm;
      			data->newRe = data->oldRe * data->oldRe - data->oldIm * data->oldIm + data->cRe;
      			data->newIm = 2 * data->oldRe * data->oldIm + data->cIm;
      			if((data->newRe * data->newRe + data->newIm * data->newIm) > 4)
					break;
				if (n < max_n)
					mlx_pixel_put(data->mlx_ptr, data->win_ptr, x, y, (data->color * n / 50));
				else if ( n == max_n)
				 	mlx_pixel_put(data->mlx_ptr, data->win_ptr, x, y, 0x000000);
			}
		}
	}
}
