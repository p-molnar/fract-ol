/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: pmolnar <pmolnar@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/01 11:32:27 by pmolnar       #+#    #+#                 */
/*   Updated: 2022/03/01 22:22:56 by pmolnar       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "../includes/fractol.h"
#include <stdio.h>

void	init_vars(t_vars *var)
{
	var->win.width= 500;
	var->win.height = 500;
	var->win.title = "Window Title";
	var->fract.max_iter = 50;
	var->fract.real.min = -2;
	var->fract.real.max = 2;
	var->fract.imag.min = -2;
	var->fract.imag.max = 2;
	var->mouse.zoom = 1.0;
}

void	init_mlx(t_vars *var)
{
	var->mlx = mlx_init();
	var->win.mlx = mlx_new_window(var->mlx, var->win.width, 
									var->win.height, var->win.title);
	var->img.img = mlx_new_image(var->mlx, var->win.width, var->win.height);
	var->img.addr = mlx_get_data_addr(var->img.img, &var->img.bits_per_pixel,
									&var->img.line_length, &var->img.endian);
}
