/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   events.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: pmolnar <pmolnar@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/03 10:34:04 by pmolnar       #+#    #+#                 */
/*   Updated: 2022/03/10 17:03:36 by pmolnar       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "../includes/fractol.h"
#include "../includes/key_consts.h"
#include <stdio.h>
#include <stdlib.h>

void	shift_colors(int keycode, t_vars *var)
{
	if (keycode == KEY_C)
		var->fract.color_palette = (var->fract.color_palette + 1) % 5;
}

void	change_itermax(int keycode, t_vars *var)
{
	if (keycode != KEY_NUMPAD_PLUS && keycode != KEY_NUMPAD_MINUS)
		return ;
	if (keycode == KEY_NUMPAD_PLUS)
		var->fract.max_iter += 5;
	else if (keycode == KEY_NUMPAD_MINUS && \
			var->fract.max_iter != 0)
		var->fract.max_iter -= 5;
	plot_fractal(var);
}

void	zoom(int keycode, int x, int y, t_vars *var)
{
	double	interpolation;

	if (keycode != MOUSE_SCROLL_UP && keycode != MOUSE_SCROLL_DOWN)
		return ;
	if (keycode == MOUSE_SCROLL_UP)
		var->mouse.zoom = 1.15;
	else if (keycode == MOUSE_SCROLL_DOWN)
		var->mouse.zoom = 0.85;

	interpolation = 1.0 / var->mouse.zoom;
	var->mouse.real = (double)(x + var->fract.x_offset) / (WIN_W / \
		(var->fract.real.max - var->fract.real.min)) + var->fract.real.min;
	var->mouse.imag = (double)(y + var->fract.y_offset) / (WIN_H / \
		(var->fract.imag.max - var->fract.imag.min)) + var->fract.imag.min;
	var->fract.real.min = interpolate(var->mouse.real, \
							var->fract.real.min, interpolation);
	var->fract.imag.min = interpolate(var->mouse.imag, \
							var->fract.imag.min, interpolation);
	var->fract.real.max = interpolate(var->mouse.real, \
							var->fract.real.max, interpolation);
	var->fract.imag.max = interpolate(var->mouse.imag, \
							var->fract.imag.max, interpolation);
	plot_fractal(var);
}

void	close_window(int keycode, t_vars *var)
{
	(void) var;
	if (keycode == KEY_ESC)
		exit(0);
}


void	key_navigation(int keycode, t_vars *var)
{
	if (keycode == ARROW_KEY_LEFT)
		var->fract.x_offset -= 7;
	else if (keycode == ARROW_KEY_RIGHT)
		var->fract.x_offset += 7;
	else if (keycode == ARROW_KEY_DOWN)
		var->fract.y_offset += 7;
	else if (keycode == ARROW_KEY_UP)
		var->fract.y_offset -= 7;
	plot_fractal(var);
}
