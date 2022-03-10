/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   colors.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: pmolnar <pmolnar@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/02 18:36:10 by pmolnar       #+#    #+#                 */
/*   Updated: 2022/03/10 22:44:08 by pmolnar       ########   odam.nl         */
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
	{104, 2, 15, 3, 13, 3},
	{96, 2, 16, 2, 99, 4},
	{46, 3, 17, 2, 22, 4},
	{25, 4, 20, 2, 34, 2},
	{26, 3, 4, 2, 15, 22}
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
