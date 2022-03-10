/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   error.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: pmolnar <pmolnar@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/08 15:13:52 by pmolnar       #+#    #+#                 */
/*   Updated: 2022/03/10 15:47:13 by pmolnar       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/errors.h"
#include <stdlib.h>
#include <stdio.h>

int	display_input_error(void)
{
	printf("\n[!] ERROR: ");
	printf("Invalid argument count\n\n");
	printf("usage: ./fractal \"<fractal-name | ");
	printf("complex-polynomial-formula>\"\n\n");
	printf("Preset fractals: \n");
	printf("[1]	Mandelbrot\n");
	printf("[2]	Julia 1\n");
	printf("[3]	Julia 2\n");
	printf("[4]	Julia 3\n");
	printf("\nExpected polynomial formulation:\n");
	printf("a + bi\n");
	return (EXIT_FAILURE);
}
