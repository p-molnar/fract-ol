/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   input.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: pmolnar <pmolnar@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/07 09:41:03 by pmolnar       #+#    #+#                 */
/*   Updated: 2022/03/08 18:18:03 by pmolnar       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"
#include "../includes/libft/libft.h"
#include <stdio.h>

bool	parse_polynomial(t_vars *var, const char *polynom)
{
	char *sign_ptr;
	int	sign;

	sign_ptr = ft_strrchr(polynom, ' ') - 1;
	if (*sign_ptr == '-')
		sign = -1;
	else if (*sign_ptr == '+')
		sign = 1;
	else
		return (false);
	if (polynom[ft_strlen(polynom) - 1] != 'i')
		return (false);
	var->fract.input_a = ft_atof(polynom);
	var->fract.input_b = sign * ft_atof(sign_ptr + 1);
	return (true);
}

bool	is_valid_arg_count(int argc)
{
	return (argc == 2);
}

bool parse_preset_fractal(t_vars *var, const char *arg)
{
	int	i;
	const char	*fractal_types[DEFAULT_FRACT_COUNT] = {
		"Mandelbrot",
		"Julia 1",
		"Julia 2",
		"Julia 3",
	};

	i = 0;
	while (i < DEFAULT_FRACT_COUNT )
	{
		if (ft_strncmp(fractal_types[i], arg, 
			ft_strlen(fractal_types[i])) == 0)
		{
			var->fract.type = arg;
			return (true);
		}
		i++;
	}
	return (false);
}

bool parse_cla(int argc, char *argv[], t_vars *var)
{
	const char	*arg;

	arg = argv[1];
	if (!is_valid_arg_count(argc))
		return (false);
	if(!parse_preset_fractal(var, arg))
	{
		if (!parse_polynomial(var, arg))
			return(false);
	}
	return (true);
}
