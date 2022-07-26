/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   events.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: pmolnar <pmolnar@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/01 21:32:42 by pmolnar       #+#    #+#                 */
/*   Updated: 2022/03/10 17:01:21 by pmolnar       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef EVENTS_H
# define EVENTS_H
# include "custom_datatypes.h"

int		window_event_handler(int keycode, t_vars *var);
int		keypress_event_handler(int keycode, t_vars *var);
int		mouse_event_handler(int button, int x, int y, t_vars *var);
void	shift_colors(int keycode, t_vars *var);
void	change_itermax(int keycode, t_vars *var);
void	zoom(int keycode, int x, int y, t_vars *var);
void	close_window(int keycode, t_vars *var);
void	key_navigation(int keycode, t_vars *var);

#endif 