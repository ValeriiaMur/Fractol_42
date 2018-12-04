/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmuradia <vmuradia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 17:54:49 by vmuradia          #+#    #+#             */
/*   Updated: 2018/12/03 22:02:04 by vmuradia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h> // delete later
#include <math.h>
#include "./libft/libft.h"
#include "./minilibx/mlx.h"
#include <tgmath.h>

#define WINDOW	1200

typedef struct	s_data
{
	void		*mlx_ptr;
	void		*win_ptr;
	void		*img_get_data;
	void		*img_ptr;
	int			fractol;
	int			*bits_p_pixel;
	int			*endian;
	int			*size_line;
	int			color;
	int			width;
	int			height;
	double 		minReal;
	double 		maxReal;
	double		min_i;
	double		max_i;
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
	data->minReal = -2.0;
	data->maxReal = 1.0;
	data->min_i = -1.0;
	data->max_i = 1.0;
	data->color = 0xd7afd7;
	mandelbrot(data);
}

int findN(double cr, double ci, double max_n)
{
	int i = 0;
	double zr = 0.0;
	double zi = 0.0;
	while ( i < max_n && zr * zr + zi * zi < 4.0)
	{
		double temp = zr * zr - zi * zi + cr;
		zi = 2.0 * zr * zi + ci;
		zr = temp;
		i++;
	}
	return (i);
}

double mapToReal(int x, t_data *data)
{
	double range = data->maxReal - data->minReal;
	return (x * (range /data->width) + data->minReal);
}

double mapToImaginary(int y, t_data *data)
{
	double range = data->max_i - data->min_i;
	return (y * (range / data->height) + data->min_i);
}

void mandelbrot(t_data *data)
{
	double	max_n = 1000;
	for (int x = 0; x < data->width; x++)
	{
		for (int y = 0; y < data->height; y++)
		{
			double cr = mapToReal(x, data);
			double ci = mapToImaginary(y, data);
			int n = findN(cr, ci, max_n);
			mlx_pixel_put(data->mlx_ptr, data->win_ptr, x, y, data->color * n);
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

int		key_press(int key, void *param)
{
	(void)param;
	if (key == 53)
		exit(1);
	return (0);
}

int main(int argc, char **argv)
{
	t_data	*data;

	if (argc == 2)
	{
		data = (t_data*)malloc(sizeof(t_data));
		data->mlx_ptr = mlx_init();
		data->win_ptr = mlx_new_window(data->mlx_ptr, 1000, 1000, "My Fractol");
		if ((fract_select(argv, data)) == 0)
			return (-1);

		//data->img_ptr = mlx_new_image(data->mlx_ptr, WINDOW, WINDOW);
	//	data->img_ptr = mlx_get_data_addr(data->img_ptr, data->bits_p_pixel,
		//data->size_line, data->endian);
		mlx_key_hook(data->win_ptr, key_press, (void *)0);
		mlx_loop(data->mlx_ptr);
		free(data);
	}

}
