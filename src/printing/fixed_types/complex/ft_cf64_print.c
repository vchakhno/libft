/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cf64_print.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchakhno <vchakhno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 11:53:45 by vchakhno          #+#    #+#             */
/*   Updated: 2023/05/17 21:37:31 by vchakhno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/ostream/ostream.h"
#include "libft/str/str.h"
#include "libft/bounds.h"
#include "libft/float_math.h"
#include "libft/printf.h"
#include <stdio.h>

bool	ft_cf64_print(t_cf64 value)
{
	return (ft_cf64_oprint(ft_stdout(), value));
}

bool	ft_cf64_println(t_cf64 value)
{
	return (ft_cf64_oprintln(ft_stdout(), value));
}

bool	ft_cf64_oprint(t_any_str_ostream *stream, t_cf64 value)
{
	t_f64	imaginary;

	ft_f64_oprint(stream, (t_f64) value);
	imaginary = ((t_f64 *)&value)[1];
	if (*(t_u64 *)&imaginary >> 63)
	{
		if (!ft_c_str_oprint(stream, " - "))
			return (false);
		imaginary = -imaginary;
	}
	else
	{
		if (!ft_c_str_oprint(stream, " + "))
			return (false);
	}
	ft_f64_oprint(stream, imaginary);
	if (*(t_u64 *)&imaginary >> 52 == 0x7FF)
	{
		if (!ft_c_str_oprint(stream, " * "))
			return (false);
	}
	ft_ostream_write_byte(stream, 'i');
	return (true);
}

bool	ft_cf64_oprintln(t_any_str_ostream *stream, t_cf64 value)
{
	if (!ft_cf64_oprint(stream, value))
		return (false);
	return (ft_ostream_write(stream, "\n", 1));
}
