/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   colors.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: pmolnar <pmolnar@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/02 18:36:10 by pmolnar       #+#    #+#                 */
/*   Updated: 2022/03/10 23:05:50 by pmolnar       ########   odam.nl         */
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
	double		t;
	int			color;
	int			i;
	const int	c[5][6] = {
	{60, 16, 20, 2, 10, 6},
	{65, 4, 60, 4, 12, 15},
	{10, 3, 50, 2, 12, 5},
	{80, 6, 11, 2, 25, 12},
	{65, 4, 20, 2, 34, 2},
	};

	t = (double) iter / var->fract.max_iter;
	i = var->fract.color_palette;
	color = rgb(c[i][0] * (1 - t) * pow(t, c[i][1]) * 255, \
				c[i][2] * pow((1 - t), c[i][3]) * pow(t, 2) * 255, \
				c[i][4] * pow((1 - t), c[i][5]) * t * 255);
	if (iter < var->fract.max_iter)
		mlx_put_pixel(&var->img, x, y, color);
	else
		mlx_put_pixel(&var->img, x, y, 0x00000000);
}
