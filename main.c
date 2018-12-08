/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmuradia <vmuradia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 16:16:50 by vmuradia          #+#    #+#             */
/*   Updated: 2018/12/07 17:11:56 by vmuradia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*
** Each fractal has a number. assign, select, init.
*/

int		fract_select(char **argv, t_data *data)
{
	if (ft_strcmp(argv[1], "mandelbrot") == 0)
	{
		data->fractol = 0;
		mandelbrot_init(data);
	}
	else if (ft_strcmp(argv[1], "julia") == 0)
	{
		data->fractol = 1;
		julia_init(data);
	}
	else if (ft_strcmp(argv[1], "fern") == 0)
	{
		data->fractol = 2;
		fern_init(data);
	}
	else
	{
		ft_putendl("Usage: ./fractol [julia] or [mandelbrot] or [fern]");
		return (0);
	}
	return (1);
}

/*
** For iterations when zooming only
*/

void	put_text(t_data *data)
{
	char	*text;
	char	*nb;

	nb = ft_itoa(data->max_n);
	text = ft_strjoin("Number of iterations : ", nb);
	mlx_string_put(data->mlx_ptr, data->win_ptr, 10, 10, 0xFFFFFF, text);
	ft_strdel(&text);
	ft_strdel(&nb);
}

int		main(int argc, char **argv)
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
		mlx_hook(data->win_ptr, 4, 0, mouse_hook, data);
		mlx_loop(data->mlx_ptr);
		free(data);
	}
	else if (argc > 2)
		ft_putendl("Too many arguments");
	else
		ft_putendl("Please specify the name of the fractol");
}
