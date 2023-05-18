/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cf128_print.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchakhno <vchakhno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 11:53:45 by vchakhno          #+#    #+#             */
/*   Updated: 2023/05/18 03:43:11 by vchakhno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/ostream/ostream.h"
#include "libft/str/str.h"
#include "libft/bounds.h"
#include "libft/float_math.h"
#include "libft/printf.h"

bool	ft_cf128_print(t_cf128 value)
{
	return (ft_cf128_oprint(ft_stdout(), value));
}

bool	ft_cf128_println(t_cf128 value)
{
	return (ft_cf128_oprintln(ft_stdout(), value));
}

bool	ft_cf128_oprint(t_any_str_ostream *stream, t_cf128 value)
{
	t_f128	imaginary;

	ft_f128_oprint(stream, (t_f128) value);
	imaginary = (t_f128)(value * -1.iq);
	if (((t_u16 *)&imaginary)[7] >> 15)
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
	ft_f128_oprint(stream, imaginary);
	if (((t_u16 *)&imaginary)[7] == 0x7FFF)
	{
		if (!ft_c_str_oprint(stream, " * "))
			return (false);
	}
	ft_ostream_write_byte(stream, 'i');
	return (true);
}

bool	ft_cf128_oprintln(t_any_str_ostream *stream, t_cf128 value)
{
	if (!ft_cf128_oprint(stream, value))
		return (false);
	return (ft_ostream_write(stream, "\n", 1));
}
