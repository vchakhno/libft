/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_i16_print.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchakhno <vchakhno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 11:53:45 by vchakhno          #+#    #+#             */
/*   Updated: 2023/05/04 19:41:30 by vchakhno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/ostream/ostream.h"
#include "libft/bounds.h"
#include "libft/printf.h"

bool	ft_i16_print(t_i16 value)
{
	return (ft_i16_oprint(value, ft_stdout()));
}

bool	ft_i16_println(t_i16 value)
{
	return (ft_i16_oprintln(value, ft_stdout()));
}

bool	ft_i16_oprint(t_i16 value, t_any_str_ostream *stream)
{
	if (value < 0)
	{
		if (!ft_ostream_write(stream, "-", 1))
			return (false);
	}
	if (value / 10)
	{
		if (!ft_i16_oprint(ft_i16_abs(value / 10), stream))
			return (false);
	}
	return (ft_ostream_write(stream, &(char){ft_i16_abs(value % 10) + '0'}, 1));
}

bool	ft_i16_oprintln(t_i16 value, t_any_str_ostream *stream)
{
	if (!ft_i16_oprint(value, stream))
		return (false);
	return (ft_ostream_write(stream, "\n", 1));
}
