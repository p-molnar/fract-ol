/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fractol.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: pmolnar <pmolnar@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/01 11:24:39 by pmolnar       #+#    #+#                 */
/*   Updated: 2022/03/01 21:41:14 by pmolnar       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include "custom_datatypes.h"

void	mlx_put_pixel(t_data *data, int x, int y, int color);
void	init_vars(t_vars *var);
void	init_mlx(t_vars *var);
void	draw_fractal(t_vars *var);
int	render_next_frame(t_vars *var);

#endif
