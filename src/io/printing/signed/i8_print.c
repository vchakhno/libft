/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   i8_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchakhno <vchakhno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 11:53:45 by vchakhno          #+#    #+#             */
/*   Updated: 2023/06/03 21:35:34 by vchakhno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/io/printing.h"
#include "libft/arithmetic/bounds.h"
#include "libft/io/printf.h"

bool	ft_i8_print(t_i8 value)
{
	return (ft_i8_oprint(ft_stdout(), value));
}

bool	ft_i8_println(t_i8 value)
{
	return (ft_i8_oprintln(ft_stdout(), value));
}

bool	ft_i8_oprint(t_any_str_ostream *any_stream, t_i8 value)
{
	if (value < 0)
	{
		if (!ft_ostream_write(any_stream, "-", 1))
			return (false);
	}
	if (value / 10)
	{
		if (!ft_i8_oprint(any_stream, ft_i8_abs(value / 10)))
			return (false);
	}
	return (
		ft_ostream_write(any_stream, &(char){ft_i8_abs(value % 10) + '0'}, 1)
	);
}

bool	ft_i8_oprintln(t_any_str_ostream *any_stream, t_i8 value)
{
	if (!ft_i8_oprint(any_stream, value))
		return (false);
	return (ft_ostream_write(any_stream, "\n", 1));
}
