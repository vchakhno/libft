/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f64_print.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchakhno <vchakhno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 11:53:45 by vchakhno          #+#    #+#             */
/*   Updated: 2023/06/03 20:47:59 by vchakhno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/io/printing.h"
#include "libft/data/str.h"
#include "libft/arithmetic/bounds.h"
#include "libft/io/printf.h"
#include "libft/arithmetic/float_math.h"

static bool	ft_f64_print_numerical_part(
	t_any_ostream *stream, t_f64 value, t_i16 log
) {
	t_i16	i;
	t_f64	mask;
	t_i16	snapped_log;

	snapped_log = (log - 2 * (log < 0)) / 3 * 3;
	mask = ft_f64_10pow(log);
	i = 0;
	while (i < 4)
	{
		if (!ft_ostream_write_byte(stream, ft_f64_mod(value / mask, 10) + '0'))
			return (false);
		if (log - i < snapped_log
			&& ft_f64_abs(ft_f64_mod(value, mask * 10) < mask / 1000))
			return (true);
		if (log - i == snapped_log)
			if (!ft_ostream_write(stream, ".", 1))
				return (false);
		mask /= 10.000001;
		i++;
	}
	return (true);
}

bool	ft_f64_print(t_f64 value)
{
	return (ft_f64_oprint(ft_stdout(), value));
}

bool	ft_f64_println(t_f64 value)
{
	return (ft_f64_oprintln(ft_stdout(), value));
}

bool	ft_f64_oprint(t_any_str_ostream *stream, t_f64 value)
{
	t_i16	log;

	if (*(t_u64 *)&value >> 63)
	{
		if (!ft_ostream_write(stream, "-", 1))
			return (false);
		value = -value;
	}
	if (*(t_u64 *)&value == 0x7FFl << 52)
		return (ft_c_str_oprint(stream, "Infinity"));
	if (*(t_u64 *)&value > 0x7FFl << 52)
		return (ft_c_str_oprint(stream, "NaN"));
	log = ft_f64_log10(value);
	if (!ft_f64_print_numerical_part(stream, value, log))
		return (false);
	if (log < 0 || 3 <= log)
	{
		if (!ft_ostream_write(stream, "e", 1))
			return (false);
		if (!ft_i16_oprint(stream, (log - 2 * (log < 0)) / 3 * 3))
			return (false);
	}
	return (true);
}

bool	ft_f64_oprintln(t_any_str_ostream *stream, t_f64 value)
{
	if (!ft_f64_oprint(stream, value))
		return (false);
	return (ft_ostream_write(stream, "\n", 1));
}
