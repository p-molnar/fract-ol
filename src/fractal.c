/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fractal.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: pmolnar <pmolnar@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/02 18:00:13 by pmolnar       #+#    #+#                 */
/*   Updated: 2022/03/03 10:21:05 by pmolnar       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

#include <stdio.h>
#include <math.h>


double interpolate(double start, double end, double interpolation)
{
    return start + ((end - start) * interpolation);
}

int	calc_mandelbrot(t_vars *var)
{
	double	x;
	double	y;
	double	x_tmp;
	int		iter;

	x = 0;
	y = 0;
	iter = 0;
	while (x*x + y*y <= 4 && iter < var->fract.max_iter)
	{
		x_tmp = x*x - y*y + var->fract.real.val;
		y = 2*x*y + var->fract.imag.val;
		x = x_tmp;
		iter++;
	}
	return (iter);
}

void	draw_fractal(t_vars *var)
{
	int	ix;
	int	iy;
	int	magnitude;

	iy = 0;
	while (iy < WIN_H)
	{
		var->fract.imag.val = interpolate(var->fract.imag.min, var->fract.imag.max,
											(double)iy/WIN_H);
		ix = 0;
		while (ix < WIN_W)
		{
			var->fract.real.val = interpolate(var->fract.real.min, var->fract.real.max, (double)ix/WIN_W);	
			magnitude = calc_mandelbrot(var);
			color_pixel(var, magnitude, ix, iy);
			ix++;
		}
		iy++;
	}
}