/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   events.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: pmolnar <pmolnar@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/03 10:34:04 by pmolnar       #+#    #+#                 */
/*   Updated: 2022/03/05 20:24:03 by pmolnar       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "../includes/fractol.h"
#include "../includes/key_consts.h"
#include <stdio.h>
#include <stdlib.h>

void	print_info(int keycode, t_vars *var)
{
	if (keycode != KEY_I)
		return ;
	printf("--- info ---\n");
	printf("zoom: %f\n", var->mouse.zoom);
	// printf("mouse_x: %d\n", x);
	// printf("mouse_y: %d\n", y);
	printf("mouse_real: %f\n", var->mouse.real);
	printf("mouse_imag: %f\n", var->mouse.imag);
	printf("real.min: %f\n", var->fract.real.min);
	printf("real.max: %f\n", var->fract.real.max);
	printf("imag.min: %f\n", var->fract.imag.min);
	printf("imag.max: %f\n", var->fract.imag.max);
	printf("--- **** ---\n");
}

void	change_itermax(int keycode, t_vars *var)
{
	if (keycode != KEY_NUMPAD_PLUS && keycode != KEY_NUMPAD_MINUS)
		return ;
	if (keycode == KEY_NUMPAD_PLUS)
		var->fract.max_iter += 5;
	else if (keycode == KEY_NUMPAD_MINUS && 
			var->fract.max_iter != 0)
		var->fract.max_iter -= 5;
	plot_fractal(var);
}

void	zoom(int keycode, int x, int y, t_vars *var)
{
	if (keycode != MOUSE_SCROLL_UP && keycode != MOUSE_SCROLL_DOWN)
		return ;
	if (keycode == MOUSE_SCROLL_UP)
		var->mouse.zoom = 1.15;
	else if (keycode == MOUSE_SCROLL_DOWN)
		var->mouse.zoom = 0.85;

	var->mouse.real = (double)x / (WIN_W / (var->fract.real.max - var->fract.real.min)) + var->fract.real.min;
	var->mouse.imag = (double)y / (WIN_H / (var->fract.imag.max - var->fract.imag.min)) + var->fract.imag.min;
	double interpolation = 1.0 / var->mouse.zoom;
	var->fract.real.min = interpolate(var->mouse.real, var->fract.real.min, interpolation);
	var->fract.imag.min = interpolate(var->mouse.imag, var->fract.imag.min, interpolation);
	var->fract.real.max = interpolate(var->mouse.real, var->fract.real.max, interpolation);
	var->fract.imag.max = interpolate(var->mouse.imag, var->fract.imag.max, interpolation);
	plot_fractal(var);
}

void	close_window(int keycode, t_vars *var)
{
	(void) keycode;
	(void) var;
	exit(0);
}