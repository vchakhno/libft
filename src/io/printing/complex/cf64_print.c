/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cf64_print.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchakhno <vchakhno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 11:53:45 by vchakhno          #+#    #+#             */
/*   Updated: 2023/10/14 11:07:19 by vchakhno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/io/printing.h"
#include "libft/data/str.h"
#include "libft/arithmetic/bounds.h"
#include "libft/arithmetic/float_math.h"
#include "libft/io/printf.h"

bool	ft_cf64_print(t_cf64 value)
{
	return (ft_cf64_oprint(value, ft_stdout()));
}

bool	ft_cf64_println(t_cf64 value)
{
	return (ft_cf64_oprintln(value, ft_stdout()));
}

bool	ft_cf64_oprint(t_cf64 value, t_output *output)
{
	t_f64	imaginary;

	ft_f64_oprint((t_f64) value, output);
	imaginary = ((t_f64 *)&value)[1];
	if (*(t_u64 *)&imaginary >> 63)
	{
		if (!ft_c_str_oprint(" - ", output))
			return (false);
		imaginary = -imaginary;
	}
	else
	{
		if (!ft_c_str_oprint(" + ", output))
			return (false);
	}
	ft_f64_oprint(imaginary, output);
	if (*(t_u64 *)&imaginary >> 52 == 0x7FF)
	{
		if (!ft_c_str_oprint(" * ", output))
			return (false);
	}
	ft_output_write_byte(output, 'i');
	return (true);
}

bool	ft_cf64_oprintln(t_cf64 value, t_output *output)
{
	if (!ft_cf64_oprint(value, output))
		return (false);
	return (ft_output_write(output, "\n", 1));
}
