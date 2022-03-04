/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fractal.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: pmolnar <pmolnar@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/02 18:00:13 by pmolnar       #+#    #+#                 */
/*   Updated: 2022/03/04 22:19:22 by pmolnar       ########   odam.nl         */
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
	double	a;
	double	b;
	double	a_tmp;
	int		iter;

	a = var->fract.real.init;
	b = var->fract.imag.init;
	iter = 0;
	while (a*a + b*b <= 4 && iter < var->fract.max_iter)
	{
		a_tmp = a*a - b*b + var->fract.real.val;
		b = 2*a*b + var->fract.imag.val;
		a = a_tmp;
		iter++;
	}
	var->fract.z = a*a + b*b;
	return (iter);
}

void	draw_fractal(t_vars *var)
{
	int	ix;
	int	iy;
	int	iter_count;

	iy = 0;
	while (iy < WIN_H)
	{
		var->fract.imag.val = interpolate(var->fract.imag.min, var->fract.imag.max,
											(double)iy/WIN_H);
		ix = 0;
		while (ix < WIN_W)
		{
			var->fract.real.val = interpolate(var->fract.real.min, var->fract.real.max, (double)ix/WIN_W);	
			iter_count = calc_mandelbrot(var);
			color_pixel(var, iter_count, ix, iy);
			ix++;
		}
		iy++;
	}
}