/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   renderer.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: pmolnar <pmolnar@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/01 11:21:22 by pmolnar       #+#    #+#                 */
/*   Updated: 2022/03/10 22:38:32 by pmolnar       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/custom_datatypes.h"
#include <mlx.h>
#include <stdlib.h>
#include <stdio.h>

void	mlx_put_pixel(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * \
						(data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	render_next_frame(t_vars *var)
{
	mlx_put_image_to_window(var->mlx, var->win.mlx, var->img.img, 0, 0);
	return (EXIT_SUCCESS);
}
