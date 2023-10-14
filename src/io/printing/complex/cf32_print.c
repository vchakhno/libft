/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cf32_print.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchakhno <vchakhno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 11:53:45 by vchakhno          #+#    #+#             */
/*   Updated: 2023/10/14 11:06:06 by vchakhno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/io/printing.h"
#include "libft/data/str.h"
#include "libft/arithmetic/bounds.h"
#include "libft/arithmetic/float_math.h"
#include "libft/io/printf.h"

bool	ft_cf32_print(t_cf32 value)
{
	return (ft_cf32_oprint(value, ft_stdout()));
}

bool	ft_cf32_println(t_cf32 value)
{
	return (ft_cf32_oprintln(value, ft_stdout()));
}

bool	ft_cf32_oprint(t_cf32 value, t_output *output)
{
	t_f32	imaginary;

	ft_f32_oprint((t_f32) value, output);
	imaginary = ((t_f32 *)&value)[1];
	if (*(t_u32 *)&imaginary >> 31)
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
	ft_f32_oprint(imaginary, output);
	if (*(t_u32 *)&imaginary >> 23 == 0xFF)
	{
		if (!ft_c_str_oprint(" * ", output))
			return (false);
	}
	ft_output_write_byte(output, 'i');
	return (true);
}

bool	ft_cf32_oprintln(t_cf32 value, t_output *output)
{
	if (!ft_cf32_oprint(value, output))
		return (false);
	return (ft_output_write(output, "\n", 1));
}
