/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   custom_datatypes.h                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: pmolnar <pmolnar@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/01 11:03:22 by pmolnar       #+#    #+#                 */
/*   Updated: 2022/03/02 17:09:33 by pmolnar       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUSTOM_DATATYPES_H
# define CUSTOM_DATATYPES_H

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct	s_win_data
{
	void	*mlx;
	int		width;
	int		height;
	char	*title;
}				t_win_data;

typedef struct	s_complex
{
	double		val;
	double		min;
	double		max;
}				t_complex;

typedef struct	s_fractal
{
	t_complex	imag;
	t_complex	real;
	int			max_iter;
}				t_fractal;

typedef struct	s_mouse
{
	int		x;
	int		y;
	double	real;
	double	imag;
	double	zoom;
}				t_mouse;

typedef struct	s_vars
{
	void		*mlx;
	t_data		img;
	t_win_data	win;
	t_fractal	fract;
	t_mouse		mouse;
}				t_vars;

#endif