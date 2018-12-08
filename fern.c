/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fern.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmuradia <vmuradia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 19:22:49 by vmuradia          #+#    #+#             */
/*   Updated: 2018/12/07 16:29:42 by vmuradia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void fern_init(t_data *data)
{
	data->width = 1000;
	data->height = 1000;
	data->oldRe = 0;
	data->newRe = 0;
	data->oldIm = 0;
	data->newIm = 0;
	data->color = 0x00ff00;
	data->zoom = 1;
	fern(data);
}

void second_part(t_data *data)
{
	if(data->random>=1 && data->random<=7)
	{
		data->newRe = -0.15*data->oldRe + 0.28*data->oldIm * data->zoom;
		data->newIm = 0.26*data->oldRe + 0.24*data->oldIm + 0.44 * data->zoom;
	}
	else if(data->random>=8 && data->random<=15){
		data->newRe = 0.2*data->oldRe - 0.26*data->oldIm * data->zoom;
		data->newIm = 0.23*data->oldRe + 0.22*data->oldIm + 1.6 * data->zoom;
	}
	else
	{
		data->newRe = 0.85*data->oldRe + 0.04*data->oldIm * data->zoom;
		data->newIm = -0.04*data->oldRe + 0.85*data->oldIm + 1.6 * data->zoom;
	}
}

void fern(t_data *data)
{
	data->max_n = 10000;
	while(data->max_n > 0)
	{
		data->random = rand()%100;
		if(data->random == 0)
		{
			data->newRe = 0 * data->zoom;
			data->newIm = 0.16 * data->oldIm * data->zoom;
		}
		else
			second_part(data);
		mlx_pixel_put(data->mlx_ptr, data->win_ptr, 30*data->newRe +
			data->width/2, 50*data->newIm + data->height / 3, data->color);
		data->oldRe = data->newRe;
		data->oldIm = data->newIm;
		data->max_n--;
	}
}
