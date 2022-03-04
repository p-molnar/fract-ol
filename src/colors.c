/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   colors.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: pmolnar <pmolnar@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/02 18:36:10 by pmolnar       #+#    #+#                 */
/*   Updated: 2022/03/04 18:24:13 by pmolnar       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <math.h>
#include "../includes/fractol.h"
#include <stdio.h>

int	trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

int	rgb(int r, int g, int b)
{
	return (r << 16 | g << 8 | b);
}

void	color_pixel(t_vars *var, int iter, int x, int y)
{
	// int	R[5] = {0, 32, 237, 255, 0};
	// int	G[5] = {7, 107, 255, 170, 2};
	// int	B[5] = {100, 203, 255, 0, 0};
	double	t;
	int		color;

	t = (double) iter / var->fract.max_iter;
	color = rgb(19 * (1 - t) * pow(t, 3) * 255,
			15 * pow((1 - t), 2) * pow(t, 2) * 255,
			8.5 * pow((1 - t), 2) * t * 255);
	
	if (iter < var->fract.max_iter)
	{
		mlx_put_pixel(&var->img, x, y, color);	
	}
	else
		mlx_put_pixel(&var->img, x, y, 0x00000000);	
}