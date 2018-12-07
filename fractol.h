/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmuradia <vmuradia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 16:09:35 by vmuradia          #+#    #+#             */
/*   Updated: 2018/12/06 20:12:42 by vmuradia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

#include <unistd.h>
#include <math.h>
#include "./libft/libft.h"
#include "./minilibx/mlx.h"
#include <stdio.h> //delete later

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
	double		cRe;
	double		cIm;
	double		moveX;
	double		moveY;
	double		newRe;
	double		newIm;
	double		oldRe;
	double		oldIm;
	double		zoom;
	double max_n;
	int julia_mouse;
}				t_data;

void 	mandelbrot_init(t_data *data);
int 	findN(double cr, double ci, double max_n);
void	ft_zoom(int x, int y, t_data *data);
void	ft_dezoom(int x, int y, t_data *data);
double 	find_real(int x, t_data *data);
double 	find_imaginary(int y, t_data *data);
void 	mandelbrot(t_data *data);
int 	fract_select(char **argv, t_data *data);
int 	keys(int key, t_data *data);
void	julia(t_data *data);
void	julia_init(t_data *data);
void 	zoom_julia(t_data *data);
int 	mouse_hook(int mousecode, int x,int y, t_data *data);
void	put_text(t_data *data);
int		mouse_julia(int x, int y, t_data *data);


#endif
