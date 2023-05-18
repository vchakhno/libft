/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   u8_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchakhno <vchakhno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 11:53:45 by vchakhno          #+#    #+#             */
/*   Updated: 2023/05/18 08:02:06 by vchakhno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/io/printing/printing_fixed_types.h"
#include "libft/io/printing/printf.h"

bool	ft_u8_print(t_u8 value)
{
	return (ft_u8_oprint(ft_stdout(), value));
}

bool	ft_u8_println(t_u8 value)
{
	return (ft_u8_oprintln(ft_stdout(), value));
}

bool	ft_u8_oprint(t_any_str_ostream *stream, t_u8 value)
{
	if (value >= 10)
	{
		if (!ft_u8_oprint(stream, value / 10))
			return (false);
	}
	return (ft_ostream_write(stream, &(char){value % 10 + '0'}, 1));
}

bool	ft_u8_oprintln(t_any_str_ostream *stream, t_u8 value)
{
	if (!ft_u8_oprint(stream, value))
		return (false);
	return (ft_ostream_write(stream, "\n", 1));
}
