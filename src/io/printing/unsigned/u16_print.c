/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   u16_print.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchakhno <vchakhno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 11:53:45 by vchakhno          #+#    #+#             */
/*   Updated: 2023/06/03 21:30:03 by vchakhno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/io/printing.h"
#include "libft/io/printf.h"

bool	ft_u16_print(t_u16 value)
{
	return (ft_u16_oprint(ft_stdout(), value));
}

bool	ft_u16_println(t_u16 value)
{
	return (ft_u16_oprintln(ft_stdout(), value));
}

bool	ft_u16_oprint(t_any_str_ostream *any_stream, t_u16 value)
{
	if (value >= 10)
	{
		if (!ft_u16_oprint(any_stream, value / 10))
			return (false);
	}
	return (ft_ostream_write(any_stream, &(char){value % 10 + '0'}, 1));
}

bool	ft_u16_oprintln(t_any_str_ostream *any_stream, t_u16 value)
{
	if (!ft_u16_oprint(any_stream, value))
		return (false);
	return (ft_ostream_write(any_stream, "\n", 1));
}
