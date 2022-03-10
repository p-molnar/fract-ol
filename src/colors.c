/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   colors.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: pmolnar <pmolnar@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/02 18:36:10 by pmolnar       #+#    #+#                 */
/*   Updated: 2022/03/10 09:49:54 by pmolnar       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <math.h>
#include "../includes/fractol.h"
#include <stdio.h>

int	rgb(int r, int g, int b)
{
	return (r << 16 | g << 8 | b);
}

void	color_pixel(t_vars *var, int iter, int x, int y)
{
	double	t;
	int		color;

	t = (double) iter / var->fract.max_iter;
	color = rgb(19 * (1 - t) * pow(t, 3) * 255,
			15 * pow((1 - t), 2) * pow(t, 2) * 255,
			8.5 * pow((1 - t), 2) * t * 255);
	if (iter < var->fract.max_iter)
		mlx_put_pixel(&var->img, x, y, color);
	else
		mlx_put_pixel(&var->img, x, y, 0x00000000);
}
