/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f80_print.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchakhno <vchakhno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 11:53:45 by vchakhno          #+#    #+#             */
/*   Updated: 2023/06/03 21:33:56 by vchakhno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/io/printing.h"
#include "libft/data/str.h"
#include "libft/arithmetic/bounds.h"
#include "libft/io/printf.h"
#include "libft/arithmetic/float_math.h"

static bool	ft_f80_print_numerical_part(
	t_any_ostream *any_stream, t_f80 value, t_i16 log
) {
	t_i16	i;
	t_f80	mask;
	t_i16	snapped_log;

	snapped_log = (log - 2 * (log < 0)) / 3 * 3;
	mask = ft_f80_10pow(log);
	i = 0;
	while (i < 4)
	{
		if (!ft_ostream_write_byte(
				any_stream, ft_f80_mod(value / mask, 10) + '0'))
			return (false);
		if (log - i < snapped_log
			&& ft_f80_abs(ft_f80_mod(value, mask * 10) < mask / 1000))
			return (true);
		if (log - i == snapped_log)
			if (!ft_ostream_write(any_stream, ".", 1))
				return (false);
		mask /= 10.000001l;
		i++;
	}
	return (true);
}

bool	ft_f80_print(t_f80 value)
{
	return (ft_f80_oprint(ft_stdout(), value));
}

bool	ft_f80_println(t_f80 value)
{
	return (ft_f80_oprintln(ft_stdout(), value));
}

bool	ft_f80_oprint(t_any_str_ostream *any_stream, t_f80 value)
{
	t_i16	log;

	if (((t_u16 *)&value)[4] >> 15)
	{
		if (!ft_ostream_write(any_stream, "-", 1))
			return (false);
		value = -value;
	}
	if (((t_u16 *)&value)[4] == 0x7FFF)
	{
		if (*(t_u64 *)&value << 1 == 0)
			return (ft_c_str_oprint(any_stream, "Infinity"));
		return (ft_c_str_oprint(any_stream, "NaN"));
	}
	log = ft_f80_log10(value);
	if (!ft_f80_print_numerical_part(any_stream, value, log))
		return (false);
	if (log < 0 || 3 <= log)
	{
		if (!ft_ostream_write(any_stream, "e", 1))
			return (false);
		if (!ft_i16_oprint(any_stream, (log - 2 * (log < 0)) / 3 * 3))
			return (false);
	}
	return (true);
}

bool	ft_f80_oprintln(t_any_str_ostream *any_stream, t_f80 value)
{
	if (!ft_f80_oprint(any_stream, value))
		return (false);
	return (ft_ostream_write(any_stream, "\n", 1));
}
