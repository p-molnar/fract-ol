/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   error.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: pmolnar <pmolnar@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/08 15:13:52 by pmolnar       #+#    #+#                 */
/*   Updated: 2022/03/10 22:04:31 by pmolnar       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/errors.h"
#include <stdlib.h>
#include <stdio.h>

#define KRES  "\x1B[0m"
#define KRED  "\x1B[31m"

int	display_input_error(void)
{
	printf("\n%s[!] ERROR: Invalid argument%s\n", KRED, KRES);
	printf("usage: ./fractal <fractal-name>\n");
	printf("Preset fractals: \n");
	printf("[1]	Mandelbrot\n");
	printf("[2]	Julia 1\n");
	printf("[3]	Julia 2\n");
	printf("[4]	Julia 3\n");
	printf("[B]	Burning Ship\n\n");
	printf("usage: ./fractal <comoplex-polynomial-expression>\n");
	printf("Expected polynomial formulation:\n");
	printf("a + bi, whereby `a` representing the real, and `b` the imaginary term\n");
	return (EXIT_FAILURE);
}
