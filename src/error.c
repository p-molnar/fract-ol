/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   error.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: pmolnar <pmolnar@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/08 15:13:52 by pmolnar       #+#    #+#                 */
/*   Updated: 2022/03/08 15:18:19 by pmolnar       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int	display_input_error(void)
{
	printf("usage: ./fractal <fractal-name | polynomial>\n");
	printf("polynomial representation: a + bi\n");
	printf("preset fractals:\n");
	printf("[1]	Mandelbrot\n");
	printf("[2]	Julia 1\n");
	printf("[3]	Julia 2\n");
	printf("[4]	Julia 3\n");
	
	return (EXIT_FAILURE);
}