/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   i16_print.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchakhno <vchakhno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 11:53:45 by vchakhno          #+#    #+#             */
/*   Updated: 2023/05/18 08:02:37 by vchakhno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/io/printing/printing_fixed_types.h"
#include "libft/arithmetic/bounds.h"
#include "libft/io/printing/printf.h"

bool	ft_i16_print(t_i16 value)
{
	return (ft_i16_oprint(ft_stdout(), value));
}

bool	ft_i16_println(t_i16 value)
{
	return (ft_i16_oprintln(ft_stdout(), value));
}

bool	ft_i16_oprint(t_any_str_ostream *stream, t_i16 value)
{
	if (value < 0)
	{
		if (!ft_ostream_write(stream, "-", 1))
			return (false);
	}
	if (value / 10)
	{
		if (!ft_i16_oprint(stream, ft_i16_abs(value / 10)))
			return (false);
	}
	return (ft_ostream_write(stream, &(char){ft_i16_abs(value % 10) + '0'}, 1));
}

bool	ft_i16_oprintln(t_any_str_ostream *stream, t_i16 value)
{
	if (!ft_i16_oprint(stream, value))
		return (false);
	return (ft_ostream_write(stream, "\n", 1));
}
