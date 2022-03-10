/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   event_handler.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: pmolnar <pmolnar@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/01 21:22:02 by pmolnar       #+#    #+#                 */
/*   Updated: 2022/03/10 17:01:50 by pmolnar       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"
#include "../includes/events.h"
#include "../includes/key_consts.h"
#include <stdlib.h>
#include <stdio.h>

int	window_event_handler(int keycode, t_vars *var)
{
	(void) keycode;
	close_window(KEY_ESC, var);
	return (EXIT_SUCCESS);
}

int	keypress_event_handler(int keycode, t_vars *var)
{
	shift_colors(keycode, var);
	change_itermax(keycode, var);
	close_window(keycode, var);
	key_navigation(keycode, var);
	return (EXIT_SUCCESS);
}

int	mouse_event_handler(int button, int x, int y, t_vars *var)
{
	zoom(button, x, y, var);
	return (EXIT_SUCCESS);
}
