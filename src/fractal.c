/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fractal.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: pmolnar <pmolnar@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/02 18:00:13 by pmolnar       #+#    #+#                 */
/*   Updated: 2022/03/06 00:39:24 by pmolnar       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

#include <stdio.h>
#include <math.h>


double interpolate(double start, double end, double interpolation)
{
    return start + ((end - start) * interpolation);
}

int	get_point_magnitude(t_vars *var)
{
	double	a;
	double	b;
	double	a_tmp;
	int		iter;

	// a = var->fract.real.init;
	// b = var->fract.imag.init;
	// printf("a: %f\n", *var->a);
	// printf("b: %f\n", *var->b);
	// printf("c_real: %f\n", *var->c_real);
	// printf("c_imag: %f\n", *var->c_imag);
	a = *var->a;
	b = *var->b;
	iter = 0;
	while (a*a + b*b <= 4 && iter < var->fract.max_iter)
	{
		a_tmp = a*a - b*b + *var->c_real;
		b = 2*a*b + *var->c_imag;
		a = a_tmp;
		iter++;
	}
	var->fract.z = a*a + b*b;
	return (iter);
}

void	plot_fractal(t_vars *var)
{
	int	ix;
	int	iy;
	int	iter_count;

	iy = 0;
	while (iy < WIN_H)
	{
		var->mapped_y = interpolate(var->fract.imag.min, var->fract.imag.max,
											(double)iy/WIN_H);
		ix = 0;
		while (ix < WIN_W)
		{
			var->mapped_x = interpolate(var->fract.real.min, var->fract.real.max, (double)ix/WIN_W);	
			iter_count = get_point_magnitude(var);
			color_pixel(var, iter_count, ix, iy);
			ix++;
		}
		iy++;
	}
}