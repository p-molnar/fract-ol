/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fractol.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: pmolnar <pmolnar@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/01 11:24:39 by pmolnar       #+#    #+#                 */
/*   Updated: 2022/03/10 10:30:04 by pmolnar       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include "custom_datatypes.h"
# include "fractol.h"
# include <stdbool.h>

# define WIN_W 800
# define WIN_H 800
# define DEFAULT_FRACT_COUNT 4

void	mlx_put_pixel(t_data *data, int x, int y, int color);
void	init_generic_vars(t_vars *var);
void	init_mlx(t_vars *var);
void	plot_fractal(t_vars *var);
int		render_next_frame(t_vars *var);
double	interpolate(double start, double end, double interpolation);
void	init_mandelbrot_consts(t_vars *var);
void	init_julia_consts(t_vars *var);
void	init_polynomial_consts(t_vars *var);

void	init_fractal_vars(t_vars *var);
bool	invoke_fractal_initialiser(t_vars *var);
void	set_mandelbrot_vars(t_vars *var);
void	set_julia_vars(t_vars *var);
void	set_polynomial_vars(t_vars *var);

#endif
