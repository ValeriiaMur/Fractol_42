/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmuradia <vmuradia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 16:16:50 by vmuradia          #+#    #+#             */
/*   Updated: 2018/12/04 16:26:48 by vmuradia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int fract_select(char **argv, t_data *data)
{
	if (ft_strcmp(argv[1], "mandelbrot") == 0)
	{
		data->fractol = 0;
		fractol_init(data);
	}
	else if (ft_strcmp(argv[1], "julia") == 0)
		data->fractol = 1;
	else if (ft_strcmp(argv[1], " ") == 0)
		data->fractol = 2;
	else
	{
		ft_putendl("Usage: ./fractol [julia] or [mandelbrot] or [..]\n");
		return (0);
	}
	return (1);
}

void fractol_init(t_data *data)
{
	if (data->fractol == 0)
 		mandelbrot_init(data);
}
// 	else if (data->fract == 1)
// 		julia_init(data);
// 	else if (data->fract == 2)
// 		blah(data);
//
// }

int main(int argc, char **argv)
{
	t_data	*data;

	if (argc == 2)
	{
		data = (t_data*)malloc(sizeof(t_data));
		data->mlx_ptr = mlx_init();
		data->win_ptr = mlx_new_window(data->mlx_ptr, 1100, 1100, "My Fractol");
		if ((fract_select(argv, data)) == 0)
			return (-1);
		mlx_key_hook(data->win_ptr, keys, data);
		mlx_mouse_hook(data->win_ptr, mouse_hook, data);
		mlx_loop(data->mlx_ptr);
		free(data);
	}
}
