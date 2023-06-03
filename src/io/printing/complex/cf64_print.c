/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cf64_print.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchakhno <vchakhno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 11:53:45 by vchakhno          #+#    #+#             */
/*   Updated: 2023/06/03 21:30:03 by vchakhno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/io/printing.h"
#include "libft/data/str.h"
#include "libft/arithmetic/bounds.h"
#include "libft/arithmetic/float_math.h"
#include "libft/io/printf.h"

bool	ft_cf64_print(t_cf64 value)
{
	return (ft_cf64_oprint(ft_stdout(), value));
}

bool	ft_cf64_println(t_cf64 value)
{
	return (ft_cf64_oprintln(ft_stdout(), value));
}

bool	ft_cf64_oprint(t_any_str_ostream *any_stream, t_cf64 value)
{
	t_f64	imaginary;

	ft_f64_oprint(any_stream, (t_f64) value);
	imaginary = ((t_f64 *)&value)[1];
	if (*(t_u64 *)&imaginary >> 63)
	{
		if (!ft_c_str_oprint(any_stream, " - "))
			return (false);
		imaginary = -imaginary;
	}
	else
	{
		if (!ft_c_str_oprint(any_stream, " + "))
			return (false);
	}
	ft_f64_oprint(any_stream, imaginary);
	if (*(t_u64 *)&imaginary >> 52 == 0x7FF)
	{
		if (!ft_c_str_oprint(any_stream, " * "))
			return (false);
	}
	ft_ostream_write_byte(any_stream, 'i');
	return (true);
}

bool	ft_cf64_oprintln(t_any_str_ostream *any_stream, t_cf64 value)
{
	if (!ft_cf64_oprint(any_stream, value))
		return (false);
	return (ft_ostream_write(any_stream, "\n", 1));
}
