/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cla_parser.h                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: pmolnar <pmolnar@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/10 10:28:47 by pmolnar       #+#    #+#                 */
/*   Updated: 2022/03/10 12:51:51 by pmolnar       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLA_PARSER_H
# define CLA_PARSER_H
# include <stdbool.h>
# include "custom_datatypes.h"

void	parse_cla(char *argv[], t_vars *var);
bool	parse_preset_fractal(t_vars *var, const char *arg);
bool	parse_polynomial(t_vars *var, const char *polynom);

#endif