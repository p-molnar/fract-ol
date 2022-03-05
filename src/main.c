/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: pmolnar <pmolnar@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/01 10:37:44 by pmolnar       #+#    #+#                 */
/*   Updated: 2022/03/06 00:12:08 by pmolnar       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdlib.h>
#include "../includes/fractol.h"
#include "../includes/key_consts.h"
#include "../includes/events.h"

int	main(void)
{	
	t_vars	var;

	init_generic_vars(&var);
	init_mlx(&var);
	plot_fractal(&var);
	mlx_hook(var.win.mlx, ON_DESTROY, 0, window_event_handler, &var);
	mlx_hook(var.win.mlx, ON_KEYDOWN, 0, keypress_event_handler, &var);
	mlx_hook(var.win.mlx, ON_MOUSEDOWN, 0, mouse_event_handler, &var);
	mlx_loop_hook(var.mlx, render_next_frame, &var);
	mlx_loop(var.mlx);
	return (EXIT_SUCCESS);
}