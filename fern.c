/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fern.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmuradia <vmuradia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 19:22:49 by vmuradia          #+#    #+#             */
/*   Updated: 2018/12/07 09:59:33 by vmuradia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <time.h>
#include "fractol.h"


void fern(t_data *data)
{
	data->width = 1000;
	data->height = 1000;
	unsigned long iter = 10000;
	double x0=0;
	double y0=0;
	double x1 = 100;
	double y1 = 100;
	int diceThrow;
	time_t t;
	srand((unsigned)time(&t));

	while(iter>0){
		diceThrow = rand()%100;

		if(diceThrow==0){
			x1 = 0;
			y1 = 0.16*y0;
		}

		else if(diceThrow>=1 && diceThrow<=7){
			x1 = -0.15*x0 + 0.28*y0;
			y1 = 0.26*x0 + 0.24*y0 + 0.44;
		}

		else if(diceThrow>=8 && diceThrow<=15){
			x1 = 0.2*x0 - 0.26*y0;
			y1 = 0.23*x0 + 0.22*y0 + 1.6;
		}

		else{
			x1 = 0.85*x0 + 0.04*y0;
			y1 = -0.04*x0 + 0.85*y0 + 1.6;
		}

		mlx_pixel_put(data->mlx_ptr, data->win_ptr, 30*x1 + data->width/2, 50*y1 + data->height / 3, 0x00ff00);

		x0 = x1;
		y0 = y1;

		iter--;
	}

}
