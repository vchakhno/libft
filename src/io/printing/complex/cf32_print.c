/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cf32_print.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchakhno <vchakhno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 11:53:45 by vchakhno          #+#    #+#             */
/*   Updated: 2023/05/18 09:16:58 by vchakhno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/io/printing.h"
#include "libft/data/str/str.h"
#include "libft/arithmetic/bounds.h"
#include "libft/arithmetic/float_math.h"
#include "libft/io/printf.h"

bool	ft_cf32_print(t_cf32 value)
{
	return (ft_cf32_oprint(ft_stdout(), value));
}

bool	ft_cf32_println(t_cf32 value)
{
	return (ft_cf32_oprintln(ft_stdout(), value));
}

bool	ft_cf32_oprint(t_any_str_ostream *stream, t_cf32 value)
{
	t_f32	imaginary;

	ft_f32_oprint(stream, (t_f32) value);
	imaginary = ((t_f32 *)&value)[1];
	if (*(t_u32 *)&imaginary >> 31)
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
	ft_f32_oprint(stream, imaginary);
	if (*(t_u32 *)&imaginary >> 23 == 0xFF)
	{
		if (!ft_c_str_oprint(stream, " * "))
			return (false);
	}
	ft_ostream_write_byte(stream, 'i');
	return (true);
}

bool	ft_cf32_oprintln(t_any_str_ostream *stream, t_cf32 value)
{
	if (!ft_cf32_oprint(stream, value))
		return (false);
	return (ft_ostream_write(stream, "\n", 1));
}
