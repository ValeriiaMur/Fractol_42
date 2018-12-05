/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmuradia <vmuradia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 17:54:49 by vmuradia          #+#    #+#             */
/*   Updated: 2018/12/04 16:05:47 by vmuradia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h> // delete later
#include <math.h>
#include "./libft/libft.h"
#include "./minilibx/mlx.h"

typedef struct	s_data
{
	void		*mlx_ptr;
	void		*win_ptr;
	int			fractol;
	int			color;
	int			width;
	int			height;
	double 		minReal;
	double 		maxReal;
	double		min_i;
	double		max_i;
	double 		zoom;
}				t_data;

void mandelbrot(t_data *data);
void mandelbrot_init(t_data *data);
void mandelbrot_calc(t_data *data);
void fractol_init(t_data *data);
int fract_select(char **argv, t_data *data);

void mandelbrot_init(t_data *data)
{
	data->width = 1000; //width
	data->height = 1000; //height
	data->minReal = -2.05;
	data->maxReal = 1.2;
	data->min_i = -1.3;
	data->max_i = 1.2;
	data->color = 0xd7afd7;
	data->zoom = 300;
	mandelbrot(data);
}

int findN(double cr, double ci, double max_n)
{
	int i = 0;
	double zr = 0.0;
	double zi = 0.0;
	while (i < max_n && zr * zr + zi * zi < 4.0)
	{
		double temp = zr * zr - zi * zi + cr;
		zi = 2.0 * zr * zi + ci;
		zr = temp;
		i++;
	}
	return (i);
}

void	ft_zoom(int x, int y, t_data *data, double max_n)
{
	data->minReal = (x / data->zoom + data->minReal) - (x / (data->zoom * 1.2));
	data->min_i = (y / data->zoom + data->min_i) - (y / (data->zoom * 1.2));
	data->zoom *= 1.2;
	max_n++;
}

void	ft_dezoom(int x, int y, t_data *data, double max_n)
{
	data->minReal = (x / data->zoom + data->minReal)  - (x / (data->zoom / 1.2));
	data->min_i = (y / data->zoom + data->min_i) - (y / (data->zoom / 1.2));
	data->zoom /= 1.2;
	max_n--;
}

int		mouse_hook(int mousecode, int x, int y, t_data *data, int max_n)
{
	if (mousecode == 5 || mousecode == 2)
		ft_zoom(x, y, data, max_n);
	else if (mousecode == 4 || mousecode == 1)
		ft_dezoom(x, y, data, max_n);
	mandelbrot(data);
	return (0);
}



double find_real(int x, t_data *data)
{
	double range = data->maxReal - data->minReal;
	return (x * (range /data->width) + data->minReal);
}

double find_imaginary(int y, t_data *data)
{
	double range = data->max_i - data->min_i;
	return (y * (range / data->height) + data->min_i);
}


void mandelbrot(t_data *data)
{
	int color;
	double	max_n = 100;

	mlx_string_put(data->mlx_ptr, data->win_ptr, 500, 40, 0xffffff, "Mandelbrot Set");
	for (int x = 100; x < data->width; x++)
	{
		for (int y = 100; y < data->height; y++)
		{
			double cr = find_real(x, data);
			double ci = find_imaginary(y, data);
			int n = findN(cr, ci, max_n);
			if (n == max_n)
				mlx_pixel_put(data->mlx_ptr, data->win_ptr, x, y, 0x000000);
			else if (n > 0 && n < max_n / 2-1)
				mlx_pixel_put(data->mlx_ptr, data->win_ptr, x, y, (data->color * n / 100));
			else if (n > max_n/2 && n < max_n - 1)
				mlx_pixel_put(data->mlx_ptr, data->win_ptr, x, y, (data->color * n / 100));
		}
	}
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
	mandelbrot(data);
	return (0);
}

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
