/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmuradia <vmuradia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 16:09:35 by vmuradia          #+#    #+#             */
/*   Updated: 2018/12/04 16:14:42 by vmuradia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

#include <unistd.h>
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

void 	mandelbrot_init(t_data *data);
int 	findN(double cr, double ci, double max_n);
void	ft_zoom(int x, int y, t_data *data, double max_n);
void	ft_dezoom(int x, int y, t_data *data, double max_n);
int		mouse_hook(int mousecode, int x, int y, t_data *data, int max_n);
double 	find_real(int x, t_data *data);
double 	find_imaginary(int y, t_data *data);
void 	mandelbrot(t_data *data);
void 	fractol_init(t_data *data);
int 	fract_select(char **argv, t_data *data);
int 	keys(int key, t_data *data);


#endif
