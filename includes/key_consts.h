/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   key_consts.h                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: pmolnar <pmolnar@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/01 21:01:21 by pmolnar       #+#    #+#                 */
/*   Updated: 2022/03/03 10:30:29 by pmolnar       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef KEY_CONSTS_H
# define KEY_CONSTS_H

enum {
	ON_KEYDOWN = 2,
	ON_KEYUP = 3,
	ON_MOUSEDOWN = 4,
	ON_MOUSEUP = 5,
	ON_MOUSEMOVE = 6,
	ON_EXPOSE = 12,
	ON_DESTROY = 17,
};

enum {
	MOUSE_KEY_LEFT = 1,
	MOUSE_KEY_RIGHT = 2,
	MOUSE_SCROLL_UP = 4,
	MOUSE_SCROLL_DOWN = 5, 
};

# define KEY_ESC 53
# define KEY_Q 12
# define KEY_I 34
# define KEY_G 5

# define KEY_LEFT_ARROW 123
# define KEY_RIGHT_ARROW 124
# define KEY_DOWN_ARROW 125
# define KEY_UP_ARROW 126

# define KEY_RETURN 36
# define KEY_NUMPAD_PLUS 69
# define KEY_NUMPAD_MINUS 78

# define KEY_BRACKET_OPEN 33
# define KEY_BRACKET_CLOSE 30

#endif