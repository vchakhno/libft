/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f32_print.c                                        :+:      :+:    :+:   */
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
#include "libft/io/printf.h"
#include "libft/arithmetic/float_math.h"

static bool	ft_f32_print_numerical_part(
	t_any_ostream *stream, t_f32 value, t_i8 log
) {
	t_i8	i;
	t_f32	mask;
	t_i8	snapped_log;

	snapped_log = (log - 2 * (log < 0)) / 3 * 3;
	mask = ft_f32_10pow(log);
	i = 0;
	while (i < 4)
	{
		if (!ft_ostream_write_byte(stream, ft_f32_mod(value / mask, 10) + '0'))
			return (false);
		if (log - i < snapped_log
			&& ft_f32_abs(ft_f32_mod(value, mask * 10) < mask / 1000))
			return (true);
		if (log - i == snapped_log)
			if (!ft_ostream_write(stream, ".", 1))
				return (false);
		mask /= 10.000001f;
		i++;
	}
	return (true);
}

bool	ft_f32_print(t_f32 value)
{
	return (ft_f32_oprint(ft_stdout(), value));
}

bool	ft_f32_println(t_f32 value)
{
	return (ft_f32_oprintln(ft_stdout(), value));
}

bool	ft_f32_oprint(t_any_str_ostream *stream, t_f32 value)
{
	t_i8	log;

	if (*(t_u32 *)&value >> 31)
	{
		if (!ft_ostream_write(stream, "-", 1))
			return (false);
		value = -value;
	}
	if (*(t_u32 *)&value == 0xFF << 23)
		return (ft_c_str_oprint(stream, "Infinity"));
	if (*(t_u32 *)&value > 0xFF << 23)
		return (ft_c_str_oprint(stream, "NaN"));
	log = ft_f32_log10(value);
	if (!ft_f32_print_numerical_part(stream, value, log))
		return (false);
	if (log < 0 || 3 <= log)
	{
		if (!ft_ostream_write(stream, "e", 1))
			return (false);
		if (!ft_i8_oprint(stream, (log - 2 * (log < 0)) / 3 * 3))
			return (false);
	}
	return (true);
}

bool	ft_f32_oprintln(t_any_str_ostream *stream, t_f32 value)
{
	if (!ft_f32_oprint(stream, value))
		return (false);
	return (ft_ostream_write(stream, "\n", 1));
}
