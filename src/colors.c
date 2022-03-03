/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   colors.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: pmolnar <pmolnar@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/02 18:36:10 by pmolnar       #+#    #+#                 */
/*   Updated: 2022/03/03 22:55:43 by pmolnar       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <math.h>
#include "../includes/fractol.h"

int	trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

void	color_pixel(t_vars *var, int iter, int x, int y)
{
	double log_zn;
	double	nu;
	
	log_zn = log(var->fract.z) / 2;
	nu = log(log_zn / log(2)) / log(2);

	t_color palette[4];

	palette[0].r = 153;
	palette[1].r = 75;
	palette[2].r = 99;
	palette[3].r = 14;

	palette[0].g = 53;
	palette[1].g = 175;
	palette[2].g = 199;
	palette[3].g = 88;

	palette[0].b = 15;
	palette[1].b = 41;
	palette[2].b = 69;
	palette[3].b = 7;

	int color_1 = palette[iter % 3].r;
    int	color_2 = palette[iter % 3 + 1].r;
	int	r = interpolate(color_1, color_2, iter % 1);

	color_1 = palette[iter % 3].g;
	color_2 = palette[iter % 3 + 1].g;
	int	g = interpolate(color_1, color_2, iter % 1);

	color_1 = palette[iter % 3].b;
	color_2 = palette[iter % 3 + 1].b;
	int	b = interpolate(color_1, color_2, iter % 1);

	if (iter < var->fract.max_iter)
	{
		mlx_put_pixel(&var->img, x, y, trgb(0, r, g, b));	
	}
	else
		mlx_put_pixel(&var->img, x, y, 0x00000000);	
}