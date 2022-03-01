/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   event_handler.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: pmolnar <pmolnar@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/01 21:22:02 by pmolnar       #+#    #+#                 */
/*   Updated: 2022/03/01 22:48:55 by pmolnar       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"
#include <stdlib.h>
#include <stdio.h>

int keypress_event_handler(int keycode, t_vars *var)
{
	(void) keycode;
	(void) var;
	return (EXIT_SUCCESS);
}

double interpolate(double start, double end, double interpolation)
{
    return start + ((end - start) * interpolation);
}

void apply_zoom(t_vars* var)
{
     double interpolation = 1.0 / var->mouse.zoom;
     var->fract.real.min = interpolate(var->mouse.real, var->fract.real.min, interpolation);
     var->fract.imag.min = interpolate(var->mouse.imag, var->fract.imag.min, interpolation);
     var->fract.real.max = interpolate(var->mouse.real, var->fract.real.max, interpolation);
     var->fract.imag.max = interpolate(var->mouse.imag, var->fract.imag.max, interpolation);
}

int mouse_event_handler(int button, int x, int y, t_vars *var)
{
	if (button == 1)
	{
		var->mouse.x = x;
		var->mouse.y = y;
		var->mouse.zoom += 0.01;
		printf("zoom in\n");
	}
	else if (button == 2)
	{
		var->mouse.x = x;
		var->mouse.y = y;
		var->mouse.zoom -= 0.01;
	}

	var->mouse.real = (double)var->mouse.x / (var->win.width / (var->fract.real.max - var->fract.real.min)) + var->fract.real.min;
	var->mouse.imag = (double)var->mouse.y / (var->win.height / (var->fract.imag.max - var->fract.imag.min)) + var->fract.imag.min;
	printf("--- info ---\n");
	printf("zoom: %f\n", var->mouse.zoom);
	printf("real.min: %f\n", var->fract.real.min);
	printf("real.max: %f\n", var->fract.real.max);
	printf("imag.min: %f\n", var->fract.imag.min);
	printf("imag.max: %f\n", var->fract.imag.max);
	printf("--- **** ---\n");
	apply_zoom(var);
	draw_fractal(var);

	return (EXIT_SUCCESS);
}