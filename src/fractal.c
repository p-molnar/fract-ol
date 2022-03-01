/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fractal.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: pmolnar <pmolnar@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/01 13:32:12 by pmolnar       #+#    #+#                 */
/*   Updated: 2022/03/01 14:48:52by pmolnar       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

#include <stdio.h>
#include <math.h>

void	draw_fractal(t_vars *var)
{
	int	ix;
	int	iy;
	double	x;
	double	y;
	double 	x_tmp;
	double	iter;

	iy = 0;
	while (iy < var->win.height)
	{
		ix = 0;
		while (ix < var->win.width)
		{
			var->fract.real.val = (ix - var->win.width/2.0)*(var->fract.real.max - var->fract.real.min)/var->win.width;
       		var->fract.imag.val = (iy - var->win.height/2.0)*(var->fract.imag.max - var->fract.imag.min)/var->win.width;
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
			if (iter == var->fract.max_iter)
				mlx_put_pixel(&var->img, ix, iy, 0x00ffffff);
			else
				mlx_put_pixel(&var->img, ix, iy, 0x00000000);
			ix++;
		}
		iy++;
	}
}