/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: pmolnar <pmolnar@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/01 11:32:27 by pmolnar       #+#    #+#                 */
/*   Updated: 2022/03/07 17:13:49 by pmolnar       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "../includes/fractol.h"
#include <stdio.h>

void	init_generic_vars(t_vars *var)
{
	var->win.title = "Window Title";
	var->fract.max_iter = 75;
	var->fract.real.min = -2.0;
	var->fract.imag.min = -2.0;
	var->fract.real.max = 2.0;
	var->fract.imag.max = var->fract.imag.min + (var->fract.real.max - var->fract.real.min) * (WIN_H / WIN_W);
	var->mouse.zoom = 1.0;
}

void	init_fractal_var(t_vars *var)
{
	if ()
	
}

void	init_mandelbrot_consts(t_vars *var)
{
	static double r = 0; 
	static double i = 0;
	var->fract.real.c = &var->fract.mapped_x;
	var->fract.imag.c = &var->fract.mapped_y;
	var->fract.real.init = &r;
	var->fract.imag.init = &i;
}

void	init_julia_consts(t_vars *var, double r, double i)
{
	// static double real = &r; 
	// static double imag = &i;
	var->fract.real.c = &real;
	var->fract.imag.c = &imag;
	var->fract.real.init = &var->fract.mapped_x;
	var->fract.imag.init = &var->fract.mapped_y;
}

void	init_mlx(t_vars *var)
{
	var->mlx = mlx_init();
	var->win.mlx = mlx_new_window(var->mlx, WIN_W, 
									WIN_H, var->win.title);
	var->img.img = mlx_new_image(var->mlx, WIN_W, WIN_H);
	var->img.addr = mlx_get_data_addr(var->img.img, &var->img.bits_per_pixel,
									&var->img.line_length, &var->img.endian);
}
