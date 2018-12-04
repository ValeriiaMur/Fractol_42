/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmuradia <vmuradia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 17:54:49 by vmuradia          #+#    #+#             */
/*   Updated: 2018/12/03 19:10:28 by vmuradia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h> // delete later
#include <math.h>
#include "./libft/libft.h"
#include "./minilibx/mlx.h"

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
void	mandelbrot_calc(t_data *data);
void fractol_init(t_data *data);
int fract_select(char **argv, t_data *data);

void mandelbrot_init(t_data *data)
{
 	printf("4.here\n");
//	data->it_max = 50;
	data->width = 1000; //width
	data->height = 1000; //height
	data->minReal = -1.05;
	data->maxReal = 0.1;
	data->min_i = -1.0;
	data->max_i = 1.0;
	data->color = 265;
	mandelbrot(data);
}

int findN(double cr, double ci, double max_n)
{
	int i = 0;
	double zr = 0.0;
	double zi = 0.0;
	while ( i < max_n && zr * zr + zi < 4.0)
	{
		double temp = zr * zr - zi * zi + cr;
		zi = 2.0 * zr * zr + ci;
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
	printf("5.here\n");
	int		max_n = 50;
	// int x = 0;
	// int y = 0;
	int r;
	// for every pixel
	for (int x = 0; x < data->width; x++)
	{
		//printf("6.here\n");
		for (int y = 0; y < data->height; y++)
		{
		//	printf("This is x %d and y %d\n", x, y);
			double cr = mapToReal(x, data);
			double ci = mapToImaginary(y, data);
			int n = findN(cr, ci, max_n);
			//printf("This is x %d and y %d\n", x, y);
			mlx_pixel_put(data->mlx_ptr, data->win_ptr, x, y, (data->color * n));
		//	printf("10.here\n");
		//(data->color * n)
		}
	}
	printf("11.here\n");
}
//
//
// void mandelbrot(t_data *data)
// {
// 	printf("5.here\n");
//     int i;
// 	int j;
// 	int count;
// 	int x;
// 	int y;
//
//     // getting maximum value of x-axis of screen
//     fract_1->max_x = 500;
//     // getting maximum value of y-axis of screen
//     fract_1->max_y = 500;
//     // setting up the xscale and yscale
//     fract_1->x_scale = fract_1->x_side / fract_1->max_x;
//     fract_1->y_scale = fract_1->y_side / fract_1->max_y;
//
//     // scanning every point in that rectangular area.
//     // Each point represents a Complex number (x + yi).
//     // Iterate that complex number
//     for (y = 1; y <= fract_1->max_y - 1; y++) {
//         for (x = 1; x <= fract_1->max_x - 1; x++)
//         {
//             // c_real
//             fract_1->cx = x * fract_1->x_scale + fract_1->left;
//
//             // c_imaginary
//             fract_1->cy = y * fract_1->y_scale + fract_1->top;
//
//             // z_real
//             fract_1->zx = 0;
//
//             // z_imaginary
//             y = 0;
//             count = 0;
//
//             // Calculate whether c(c_real + c_imaginary) belongs
//             // to the Mandelbrot set or not and draw a pixel
//             // at coordinates (x, y) accordingly
//             // If you reach the Maximum number of iterations
//             // and If the distance from the origin is
//             // greater than 2 exit the loop
//
// 			// #define MAXCOUNT 30
//             while ((fract_1->zx * fract_1->zx + fract_1->zy * fract_1->zy < 4) && (count < 30))
//             {
//                 // Calculate Mandelbrot function
//                 // z = z*z + c where z is a complex number
//
//                 // tempx = z_real*_real - z_imaginary*z_imaginary + c_real
//                 fract_1->temp_x = fract_1->zx * fract_1->zx - fract_1->zy * fract_1->zy + fract_1->cx;
//
//                 // 2*z_real*z_imaginary + c_imaginary
//                 fract_1->zy = 2 * fract_1->zx * fract_1->zy + fract_1->cy;
//
//                 // Updating z_real = tempx
//                 fract_1->zx = fract_1->temp_x;
//
//                 // Increment count
//                 count++;
//             }
//
//             // To display the created fractal
// 			mlx_pixel_put(data->mlx_ptr, data->win_ptr, x , y, 0xFFDF00);
//         }
//     }
// }


void fractol_init(t_data *data)
{
	printf("3.here\n");
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

	printf("2.here\n");
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
	printf("1.here\n");

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
