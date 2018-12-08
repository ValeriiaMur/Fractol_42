/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmuradia <vmuradia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 20:35:31 by vmuradia          #+#    #+#             */
/*   Updated: 2018/12/07 17:13:13 by vmuradia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	julia_init(t_data *data)
{
	data->width = 1000;
	data->height = 1000;
	data->color = 0x006600;
	data->zoom = 1;
	data->cre = -0.7;
	data->cim = 0.27015;
	data->newre = 0;
	data->newim = 0;
	data->oldre = 0;
	data->oldim = 0;
	data->max_n = 200;
	julia(data);
}

/*
** number of iterations
*/

int		julia_n(t_data *data)
{
	int i;

	i = 0;
	while (i < data->max_n && data->newre * data->newre +
		data->newim * data->newim < 4)
	{
		data->oldre = data->newre;
		data->oldim = data->newim;
		data->newre = data->oldre * data->oldre - data->oldim *
			data->oldim + data->cre;
		data->newim = 2 * data->oldre * data->oldim + data->cim;
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
			data->newre = 1.5 * (x - data->width / 2) / (0.3 * data->zoom *
				data->width);
			data->newim = (y - data->height / 2) / (0.3 * data->zoom *
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
