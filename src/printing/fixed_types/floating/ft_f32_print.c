/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_f32_print.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchakhno <vchakhno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 11:53:45 by vchakhno          #+#    #+#             */
/*   Updated: 2023/05/06 13:32:47 by vchakhno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/ostream/ostream.h"
#include "libft/str/str.h"
#include "libft/bounds.h"
#include "libft/printf.h"

// Prints a floating-point number in scientific notation
// but for every 10^3 increments, with 4 significant numbers.
//	Example:
//		102.4
//		7.238e9
//		

void	ft_f32_scientific(t_f32 value, t_i8 *out_log10, t_f32 *out_normalized)
{
	t_i8	i;

	i = 0;
	if (-1 < value && value < 1)
	{
		while (-1 < value && value < 1)
		{
			value *= 10;
			i--;
		}
	}
	else
	{
		while (value <= -10 || 10 <= value)
		{
			value /= 10;
			i++;
		}
	}
	*out_log10 = i;
	*out_normalized = value;
}

bool	ft_f32_print(t_f32 value)
{
	return (ft_f32_oprint(value, ft_stdout()));
}

bool	ft_f32_println(t_f32 value)
{
	return (ft_f32_oprintln(value, ft_stdout()));
}

bool	ft_f32_oprint(t_f32 value, t_any_str_ostream *stream)
{
	t_i8	log;
	char	write_buffer[6];

	if (*(t_u32 *)&value >> 31)
	{
		if (!ft_ostream_write(stream, "-", 1))
			return (false);
		value = -value;
	}
	if (*(t_u32 *)&value == 0xFF << 23)
		return (ft_c_str_oprint("Infinity", stream));
	if (*(t_u32 *)&value > 0xFF << 23)
		return (ft_c_str_oprint("NaN", stream));
	ft_f32_scientific(value, &log, &value);
	write_buffer[0] = (t_u32) value % 10 + '0';
	write_buffer[1] = '.';
	write_buffer[2] = (t_u32)(value * 10) % 10 + '0';
	write_buffer[3] = (t_u32)(value * 100) % 10 + '0';
	write_buffer[4] = (t_u32)(value * 1000) % 10 + '0';
	write_buffer[5] = 'e';
	ft_ostream_write(stream, write_buffer, 6);
	ft_i8_oprint(log, stream);
	return (true);
}

bool	ft_f32_oprintln(t_f32 value, t_any_str_ostream *stream)
{
	if (!ft_f32_oprint(value, stream))
		return (false);
	return (ft_ostream_write(stream, "\n", 1));
}
