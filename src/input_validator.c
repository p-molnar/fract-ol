/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   input_validator.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: pmolnar <pmolnar@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/10 11:51:07 by pmolnar       #+#    #+#                 */
/*   Updated: 2022/03/11 10:11:23 by pmolnar       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cla_validator.h"
#include "../includes/errors.h"
#include "../includes/libft/libft.h"
#include "../includes/fractol.h"
#include <stdio.h>

bool	is_valid_arg_count(int argc)
{
	return (argc == 2);
}

int	is_valid_float(const char *formula)
{
	int	i;

	i = 0;
	if (formula[i] == '-' || formula[i] == '+')
		i++;
	while (ft_isdigit(formula[i]))
		i++;
	if (formula[i] == '.')
		i++;
	while (ft_isdigit(formula[i]))
		i++;
	return (i);
}

bool	is_valid_polynomial_formula(const char *formula)
{
	size_t	i;

	i = 0;
	i = is_valid_float(formula);
	if (formula[i] == ' ')
		i++;
	if (formula[i] == '+' || formula[i] == '-')
		i++;
	if (formula[i] == ' ')
		i++;
	i += is_valid_float(&formula[i]);
	if (formula[i] == 'i')
		i++;
	if (ft_strlen(formula) == i && formula[i - 1] == 'i')
		return (true);
	return (false);
}

bool	is_valid_preset_arg(const char *arg)
{
	size_t		i;
	const char	*fractal_types[PRESET_FRACTAL_COUNT] = {
		"Mandelbrot",
		"Julia 1",
		"Julia 2",
		"Julia 3",
		"Burning Ship"
	};

	i = 0;
	while (i < PRESET_FRACTAL_COUNT)
	{
		if (ft_strncmp(fractal_types[i], arg, ft_strlen(fractal_types[i])) == 0)
			return (true);
		i++;
	}
	return (false);
}

bool	is_valid_cla(int argc, char *argv[])
{
	const char	*arg;

	arg = argv[1];
	if (!is_valid_arg_count(argc))
		return (false);
	if (is_valid_preset_arg(arg))
		return (true);
	else if (is_valid_polynomial_formula(arg))
		return (true);
	return (false);
}
