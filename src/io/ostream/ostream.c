/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ostream.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchakhno <vchakhno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 18:32:15 by vchakhno          #+#    #+#             */
/*   Updated: 2023/06/03 20:47:59 by vchakhno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/io/ostream/ostream_internals.h"
#include "libft/data/str.h"

bool	ft_ostream_has_ended(t_any_ostream *stream)
{
	return (stream->ended);
}

bool	ft_ostream_write(t_any_ostream *stream, void *elems, t_u32 count)
{
	if (!stream->write(stream, elems, count))
	{
		stream->ended = true;
		return (false);
	}
	return (true);
}

bool	ft_ostream_write_byte(t_any_ostream *stream, t_u8 byte)
{
	if (!stream->write(stream, &byte, 1))
	{
		stream->ended = true;
		return (false);
	}
	return (true);
}
