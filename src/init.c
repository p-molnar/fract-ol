/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: pmolnar <pmolnar@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/01 11:32:27 by pmolnar       #+#    #+#                 */
/*   Updated: 2022/03/03 10:21:22 by pmolnar       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "../includes/fractol.h"
#include <stdio.h>

void	init_vars(t_vars *var)
{
	var->win.title = "Window Title";
	var->fract.max_iter = 150;
	var->fract.real.min = -2.0;
	var->fract.imag.min = -2.0;
	var->fract.real.max = 2.0;
	var->fract.imag.max = var->fract.imag.min + (var->fract.real.max - var->fract.real.min) * (WIN_H / WIN_W);
	var->mouse.zoom = 1.0;
}

void	init_mlx(t_vars *var)
{
	var->mlx = mlx_init();
	var->win.mlx = mlx_new_window(var->mlx, WIN_W, 
									WIN_H, var->win.title);
	var->img.img = mlx_new_image(var->mlx, WIN_W, WIN_H);
	var->img.addr = mlx_get_data_addr(var->img.img, &var->img.bits_per_pixel,
									&var->img.line_length, &var->img.endian);
}
