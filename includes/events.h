/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   events.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: pmolnar <pmolnar@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/01 21:32:42 by pmolnar       #+#    #+#                 */
/*   Updated: 2022/03/01 21:40:14 by pmolnar       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef EVENTS_H
# define EVENTS_H
# include "custom_datatypes.h"

int keypress_event_handler(int keycode, t_vars *var);
int mouse_event_handler(int button, int x, int y, t_vars *var);


#endif 