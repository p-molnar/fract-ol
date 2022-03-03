/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   colors.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: pmolnar <pmolnar@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/02 18:36:10 by pmolnar       #+#    #+#                 */
/*   Updated: 2022/03/03 09:26:22 by pmolnar       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "../includes/fractol.h"

int	trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

void	color_pixel(t_vars *var, int iter, int x, int y)
{
	// int	color;

	// color = trgb(99, 35, 15, 255);

	if (iter == var->fract.max_iter)
	{
		// color *= (float) iter / var->fract.max_iter;
		mlx_put_pixel(&var->img, x, y, 0x00ffffff);	
	}
	else
		mlx_put_pixel(&var->img, x, y, 0x00000000);	
}