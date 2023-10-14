/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cf128_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchakhno <vchakhno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 11:53:45 by vchakhno          #+#    #+#             */
/*   Updated: 2023/10/14 11:10:05 by vchakhno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/io/printing.h"
#include "libft/data/str.h"
#include "libft/arithmetic/bounds.h"
#include "libft/arithmetic/float_math.h"
#include "libft/io/printf.h"

bool	ft_cf128_print(t_cf128 value)
{
	return (ft_cf128_oprint(value, ft_stdout()));
}

bool	ft_cf128_println(t_cf128 value)
{
	return (ft_cf128_oprintln(value, ft_stdout()));
}

bool	ft_cf128_oprint(t_cf128 value, t_output *output)
{
	t_f128	imaginary;

	ft_f128_oprint((t_f128) value, output);
	imaginary = (t_f128)(value * -1.iq);
	if (((t_u16 *)&imaginary)[7] >> 15)
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
	ft_f128_oprint(imaginary, output);
	if (((t_u16 *)&imaginary)[7] == 0x7FFF)
	{
		if (!ft_c_str_oprint(" * ", output))
			return (false);
	}
	ft_output_write_byte(output, 'i');
	return (true);
}

bool	ft_cf128_oprintln(t_cf128 value, t_output *output)
{
	if (!ft_cf128_oprint(value, output))
		return (false);
	return (ft_output_write(output, "\n", 1));
}
