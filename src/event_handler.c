/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   event_handler.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: pmolnar <pmolnar@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/01 21:22:02 by pmolnar       #+#    #+#                 */
/*   Updated: 2022/03/03 11:47:53 by pmolnar       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"
#include "../includes/events.h"
#include "../includes/key_consts.h"
#include <stdlib.h>
#include <stdio.h>

int	window_event_handler(int keycode, t_vars *var)
{
	close_window(keycode, var);
	return (EXIT_SUCCESS);
}

int keypress_event_handler(int keycode, t_vars *var)
{
	print_info(keycode, var);
	change_itermax(keycode, var);
	return (EXIT_SUCCESS);
}

int mouse_event_handler(int button, int x, int y, t_vars *var)
{
	zoom(button, x, y, var);
	return (EXIT_SUCCESS);
}