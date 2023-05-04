/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_u32_print.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchakhno <vchakhno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 11:53:45 by vchakhno          #+#    #+#             */
/*   Updated: 2023/05/04 12:32:44 by vchakhno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/ostream/ostream.h"
#include "libft/printf.h"

bool	ft_u32_print(t_u32 value)
{
	return (ft_u32_oprint(value, ft_stdout()));
}

bool	ft_u32_println(t_u32 value)
{
	return (ft_u32_oprintln(value, ft_stdout()));
}

bool	ft_u32_oprint(t_u32 value, t_any_str_ostream *stream)
{
	if (value >= 10)
	{
		if (!ft_u32_oprint(value / 10, stream))
			return (false);
	}
	return (ft_ostream_write(stream, &(char){value % 10 + '0'}, 1));
}

bool	ft_u32_oprintln(t_u32 value, t_any_str_ostream *stream)
{
	if (!ft_u32_oprint(value, stream))
		return (false);
	return (ft_ostream_write(stream, "\n", 1));
}
