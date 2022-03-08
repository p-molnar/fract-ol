/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: pmolnar <pmolnar@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/01 11:32:27 by pmolnar       #+#    #+#                 */
/*   Updated: 2022/03/08 18:24:47 by pmolnar       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "../includes/fractol.h"
# define NULL (void *)0

void	init_generic_vars(t_vars *var)
{
	var->win.title = (char *)var->fract.type;
	var->fract.max_iter = 50;
	var->fract.real.min = -2.0;
	var->fract.imag.min = -2.0;
	var->fract.real.max = 2.0;
	var->fract.imag.max = var->fract.imag.min + (var->fract.real.max - var->fract.real.min) * (WIN_H / WIN_W);
	var->fract.type = NULL;
	var->mouse.zoom = 1.0;
}

void	init_fractal_vars(t_vars *var)
{
	if(!invoke_fractal_initialiser(var))
		set_polynomial_vars(var);	
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
