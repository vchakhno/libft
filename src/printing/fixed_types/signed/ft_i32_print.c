/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_i32_print.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchakhno <vchakhno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 11:53:45 by vchakhno          #+#    #+#             */
/*   Updated: 2023/05/08 03:37:05 by vchakhno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/ostream/ostream.h"
#include "libft/bounds.h"
#include "libft/printf.h"

bool	ft_i32_print(t_i32 value)
{
	return (ft_i32_oprint(ft_stdout(), value));
}

bool	ft_i32_println(t_i32 value)
{
	return (ft_i32_oprintln(ft_stdout(), value));
}

bool	ft_i32_oprint(t_any_str_ostream *stream, t_i32 value)
{
	if (value < 0)
	{
		if (!ft_ostream_write(stream, "-", 1))
			return (false);
	}
	if (value / 10)
	{
		if (!ft_i32_oprint(stream, ft_i32_abs(value / 10)))
			return (false);
	}
	return (ft_ostream_write(stream, &(char){ft_i32_abs(value % 10) + '0'}, 1));
}

bool	ft_i32_oprintln(t_any_str_ostream *stream, t_i32 value)
{
	if (!ft_i32_oprint(stream, value))
		return (false);
	return (ft_ostream_write(stream, "\n", 1));
}
