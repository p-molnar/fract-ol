/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: pmolnar <pmolnar@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/10 14:08:44 by pmolnar       #+#    #+#                 */
/*   Updated: 2022/03/10 16:58:30 by pmolnar       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <mlx.h>
#include "../includes/fractol.h"
#include "../includes/libft/libft.h"

void	init_generic_vars(t_vars *var)
{
	var->win.title = (char *)var->fract.name;
	var->fract.max_iter = 50;
	var->fract.real.min = -2.0;
	var->fract.imag.min = -2.0;
	var->fract.real.max = 2.0;
	var->fract.imag.max = var->fract.imag.min + \
	(var->fract.real.max - var->fract.real.min) * (WIN_H / WIN_W);
	var->mouse.zoom = 1.0;
	var->fract.x_offset = 0;
	var->fract.y_offset = 0;
	var->fract.color_palette = 0;
}

void	init_fractal_vars(t_vars *var)
{
	if (!invoke_fractal_initialiser(var))
		set_polynomial_vars(var);	
}

void	init_mlx(t_vars *var)
{
	var->mlx = mlx_init();
	var->win.mlx = mlx_new_window(var->mlx, WIN_W, \
	WIN_H, var->win.title);
	var->img.img = mlx_new_image(var->mlx, WIN_W, WIN_H);
	var->img.addr = mlx_get_data_addr(var->img.img, &var->img.bits_per_pixel, \
	&var->img.line_length, &var->img.endian);
}
