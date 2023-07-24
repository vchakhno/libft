/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cf80_print.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchakhno <vchakhno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 11:53:45 by vchakhno          #+#    #+#             */
/*   Updated: 2023/07/24 03:59:43 by vchakhno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/io/printing.h"
#include "libft/data/str.h"
#include "libft/arithmetic/bounds.h"
#include "libft/arithmetic/float_math.h"
#include "libft/io/printf.h"

bool	ft_cf80_print(t_cf80 value)
{
	return (ft_cf80_oprint(ft_stdout(), value));
}

bool	ft_cf80_println(t_cf80 value)
{
	return (ft_cf80_oprintln(ft_stdout(), value));
}

bool	ft_cf80_oprint(t_output *output, t_cf80 value)
{
	t_f80	imaginary;

	ft_f80_oprint(output, (t_f80) value);
	imaginary = ((t_f80 *)&value)[1];
	if (((t_u16 *)&imaginary)[4] >> 15)
	{
		if (!ft_c_str_oprint(output, " - "))
			return (false);
		imaginary = -imaginary;
	}
	else
	{
		if (!ft_c_str_oprint(output, " + "))
			return (false);
	}
	ft_f80_oprint(output, imaginary);
	if (((t_u16 *)&imaginary)[4] == 0x7FFF)
	{
		if (!ft_c_str_oprint(output, " * "))
			return (false);
	}
	ft_output_write_byte(output, 'i');
	return (true);
}

bool	ft_cf80_oprintln(t_output *output, t_cf80 value)
{
	if (!ft_cf80_oprint(output, value))
		return (false);
	return (ft_output_write(output, "\n", 1));
}
