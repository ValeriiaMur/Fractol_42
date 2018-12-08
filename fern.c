/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fern.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmuradia <vmuradia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 19:22:49 by vmuradia          #+#    #+#             */
/*   Updated: 2018/12/07 17:14:57 by vmuradia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	fern_init(t_data *data)
{
	data->width = 1000;
	data->height = 1000;
	data->oldre = 0;
	data->newre = 0;
	data->oldim = 0;
	data->newim = 0;
	data->color = 0x00ff00;
	data->zoom = 1;
	fern(data);
}

void	second_part(t_data *data)
{
	if (data->random >= 1 && data->random <= 7)
	{
		data->newre = -0.15 * data->oldre + 0.28 * data->oldim * data->zoom;
		data->newim = 0.26 * data->oldre + 0.24 * data->oldim + 0.44 *
			data->zoom;
	}
	else if (data->random >= 8 && data->random <= 15)
	{
		data->newre = 0.2 * data->oldre - 0.26 * data->oldim * data->zoom;
		data->newim = 0.23 * data->oldre + 0.22 * data->oldim + 1.6 *
			data->zoom;
	}
	else
	{
		data->newre = 0.85 * data->oldre + 0.04 * data->oldim * data->zoom;
		data->newim = -0.04 * data->oldre + 0.85 * data->oldim + 1.6 *
			data->zoom;
	}
}

/*
** Starts to draw here
*/

void	fern(t_data *data)
{
	mlx_string_put(data->mlx_ptr, data->win_ptr, 500, 40, 0xffffff,
		"Barnsley fern");
	data->max_n = 10000;
	while (data->max_n > 0)
	{
		data->random = rand() % 100;
		if (data->random == 0)
		{
			data->newre = 0 * data->zoom;
			data->newim = 0.16 * data->oldim * data->zoom;
		}
		else
			second_part(data);
		mlx_pixel_put(data->mlx_ptr, data->win_ptr, 30 * data->newre +
			data->width / 2, 50 * data->newim + data->height / 3, data->color);
		data->oldre = data->newre;
		data->oldim = data->newim;
		data->max_n--;
	}
}
