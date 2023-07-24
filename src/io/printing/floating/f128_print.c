/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f128_print.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchakhno <vchakhno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 11:53:45 by vchakhno          #+#    #+#             */
/*   Updated: 2023/07/24 03:59:50 by vchakhno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/io/printing.h"
#include "libft/data/str.h"
#include "libft/arithmetic/bounds.h"
#include "libft/io/printf.h"
#include "libft/arithmetic/float_math.h"

static bool	ft_f128_print_numerical_part(
	t_output *output, t_f128 value, t_i16 log
) {
	t_i16	i;
	t_f128	mask;
	t_i16	snapped_log;

	snapped_log = (log - 2 * (log < 0)) / 3 * 3;
	mask = ft_f128_powi(10, log);
	i = 0;
	while (i < 4)
	{
		if (!ft_output_write_byte(
				output, ft_f128_mod(value / mask, 10) + '0'))
			return (false);
		if (log - i < snapped_log
			&& ft_f128_abs(ft_f128_mod(value, mask * 10) < mask / 1000))
			return (true);
		if (log - i == snapped_log)
			if (!ft_output_write(output, ".", 1))
				return (false);
		mask /= 10.000001q;
		i++;
	}
	return (true);
}

bool	ft_f128_print(t_f128 value)
{
	return (ft_f128_oprint(ft_stdout(), value));
}

bool	ft_f128_println(t_f128 value)
{
	return (ft_f128_oprintln(ft_stdout(), value));
}

bool	ft_f128_oprint(t_output *output, t_f128 value)
{
	t_i16	log;

	if (((t_u16 *)&value)[7] >> 15)
	{
		if (!ft_output_write(output, "-", 1))
			return (false);
		value = -value;
	}
	if (((t_u64 *)&value)[1] == 0x7FFFl << 48 && ((t_u64 *)&value)[0] == 0)
		return (ft_c_str_oprint(output, "Infinity"));
	if (((t_u16 *)&value)[7] == 0x7FFF)
		return (ft_c_str_oprint(output, "NaN"));
	log = ft_f128_logi(value, 10);
	if (!ft_f128_print_numerical_part(output, value, log))
		return (false);
	if (log < 0 || 3 <= log)
	{
		if (!ft_output_write(output, "e", 1))
			return (false);
		if (!ft_i16_oprint(output, (log - 2 * (log < 0)) / 3 * 3))
			return (false);
	}
	return (true);
}

bool	ft_f128_oprintln(t_output *output, t_f128 value)
{
	if (!ft_f128_oprint(output, value))
		return (false);
	return (ft_output_write(output, "\n", 1));
}
