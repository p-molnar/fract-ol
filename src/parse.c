/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: pmolnar <pmolnar@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/07 09:41:03 by pmolnar       #+#    #+#                 */
/*   Updated: 2022/03/10 15:21:46 by pmolnar       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"
#include "../includes/libft/libft.h"
#include "../includes/errors.h"
#include "../includes/cla_parser.h"
#include <stdio.h>

bool	parse_polynomial(t_vars *var, const char *polynom)
{
	char	*sign_ptr;
	int		sign;

	sign_ptr = ft_strrchr(polynom, ' ');
	if (!sign_ptr)
		return (false);
	if (*(sign_ptr - 1) == '-')
		sign = -1;
	else if (*(sign_ptr - 1) == '+')
		sign = 1;
	else
		return (false);
	if (polynom[ft_strlen(polynom) - 1] != 'i')
		return (false);
	var->fract.input_a = ft_atof(polynom);
	var->fract.input_b = sign * ft_atof(sign_ptr);
	var->fract.name = polynom;
	var->fract.type = "custom";
	return (true);
}

bool	parse_preset_fractal(t_vars *var, const char *arg)
{
	int			i;
	const char	*fractal_types[DEFAULT_FRACT_COUNT] = {
		"Mandelbrot",
		"Julia 1",
		"Julia 2",
		"Julia 3",
	};

	i = 0;
	while (i < DEFAULT_FRACT_COUNT)
	{
		if (ft_strncmp(fractal_types[i], arg,
				ft_strlen(fractal_types[i])) == 0)
		{
			var->fract.name = arg;
			var->fract.type = "preset";
			return (true);
		}
		i++;
	}
	return (false);
}

void	parse_cla(char *argv[], t_vars *var)
{
	char	*arg;

	arg = argv[1];
	if (!parse_preset_fractal(var, arg))
		parse_polynomial(var, arg);
}
