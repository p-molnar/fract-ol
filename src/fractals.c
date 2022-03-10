/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fractals.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: pmolnar <pmolnar@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/08 13:13:46 by pmolnar       #+#    #+#                 */
/*   Updated: 2022/03/10 15:02:16 by pmolnar       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"
#include "../includes/libft/libft.h"
#include <stdio.h>
#include <stdbool.h>

struct s_func
{
    const char *name;
	void (*function)(t_vars *);
};

struct	s_func	functions[DEFAULT_FRACT_COUNT] =
{
	{"Mandelbrot", set_mandelbrot_vars},
	{"Julia 1", set_julia_vars},
	{"Julia 2", set_julia_vars},
	{"Julia 3", set_julia_vars}
};

bool	invoke_fractal_initialiser(t_vars *var)
{
	int	i;
	const char	*fractal_name;

	i = 0;
	fractal_name = var->fract.name;
	printf("f: %s", fractal_name);

	while (i < DEFAULT_FRACT_COUNT)
	{
		if (ft_strncmp(fractal_name, functions[i].name, \
			ft_strlen(fractal_name)) == 0)
		{
			(*functions[i].function)(var);
			return (true);
		}
		i++;
	}
	return (false);
}

void	set_mandelbrot_vars(t_vars *var)
{
	static double	r;
	static double	i;

	r = 0;
	i = 0;
	var->fract.real.c = &var->fract.mapped_x;
	var->fract.imag.c = &var->fract.mapped_y;
	var->fract.real.init = &r;
	var->fract.imag.init = &i;
}

void	set_julia_vars(t_vars *var)
{	
	static double	a[3] = {-0.4, 0.285, -0.70176};
	static double	b[3] = {0.6, 0.01, -0.3842};
	int				i;

	i = ft_atoi(ft_strrchr(var->fract.name, ' ')) - 1;
	var->fract.real.c = &a[i];
	var->fract.imag.c = &b[i];
	var->fract.real.init = &var->fract.mapped_x;
	var->fract.imag.init = &var->fract.mapped_y;
}

void	set_polynomial_vars(t_vars *var)
{
	var->fract.real.c = &var->fract.input_a;
	var->fract.imag.c = &var->fract.input_b;
	var->fract.real.init = &var->fract.mapped_x;
	var->fract.imag.init = &var->fract.mapped_y;
}
