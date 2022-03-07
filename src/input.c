/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   input.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: pmolnar <pmolnar@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/07 09:41:03 by pmolnar       #+#    #+#                 */
/*   Updated: 2022/03/07 17:07:46 by pmolnar       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"
#include "../includes/libft/libft.h"
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdio.h>

bool	parse_polynomial(const char *formula, t_vars *var)
{
	(void) var;
	double		a;
	double		b;
	int			sign;
	char		*sign_ptr;

	sign = 1;
	sign_ptr = ft_strrchr(formula, ' ') - 1;
	if (*sign_ptr == '-')
		sign = -1;
	a = atof(formula);
	b = sign * atof(ft_strrchr(formula, ' '));
	printf("a: %f\n", a);
	printf("b: %f\n", b);
	return (true);
}

bool	is_valid_arg_count(int argc)
{
	return (argc == 2);
}

bool parse_arg(char *argv[], t_vars *var)
{
	int	i;
	const char *arg = argv[1];
	const char	*fractal_types[NUM_OF_FRACT_TYPE] = {
		"Mandelbrot",
		"Julia 1",
		"Julia 2",
		"Julia 3",
		"Julia 4"
	};

	i = 0;
	while (i < NUM_OF_FRACT_TYPE)
	{
		if (ft_strncmp(fractal_types[i], arg, 
			ft_strlen(fractal_types[i])) == 0)
		{
			var->fract.type = argv;
		}
		i++;
	}
	if (!parse_polynomial(arg, var))
		return (false);
	return (true);
}

bool parse_cla(int argc, char *argv[], t_vars *var)
{
	(void) var;
	if (!is_valid_arg_count(argc))
		return (false);
	else if (!parse_arg(argv, var))
		return (false);
	else
		return (true);
}
