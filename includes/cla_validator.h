/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cla_validator.h                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: pmolnar <pmolnar@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/10 10:47:39 by pmolnar       #+#    #+#                 */
/*   Updated: 2022/03/10 15:12:44 by pmolnar       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLA_VALIDATOR_H
# define CLA_VALIDATOR_H

# include <stdbool.h>
# include "custom_datatypes.h"

bool	is_valid_arg_count(int argc);
bool	is_valid_preset_arg(const char *arg);
int		get_cla_type(const char *arg);
bool	is_valid_cla(int argc, char *argv[]);
bool	is_valid_polynomial_formula(const char *formula);

#endif