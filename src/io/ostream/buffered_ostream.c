/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffered_ostream.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchakhno <vchakhno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 18:32:15 by vchakhno          #+#    #+#             */
/*   Updated: 2023/07/23 21:25:18 by vchakhno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/io/ostream.h"
#include "libft/data/mem.h"
#include "libft/arithmetic/bounds.h"

void	ft_buffered_ostream_init(
	t_buffered_ostream *stream,
	void *buffer, t_u32 buffer_size, t_any_ostream *any_destination
) {
	ft_ostream_base_init(&stream->base, ft_buffered_ostream_write);
	stream->buffer = buffer;
	stream->buffer_size = buffer_size;
	stream->pos = 0;
	stream->any_destination = any_destination;
}

bool	ft_buffered_ostream_write(
	t_buffered_ostream *stream, void *ptr, t_u32 size
) {
	t_u32	written;

	if (size < stream->buffer_size - stream->pos)
	{
		ft_mem_copy(stream->buffer + stream->pos, ptr, size);
		stream->pos += size;
	}
	else if (size < 2 * stream->buffer_size - stream->pos)
	{
		written = stream->buffer_size - stream->pos;
		ft_mem_copy(stream->buffer + stream->pos, ptr, written);
		if (!ft_ostream_write(stream->any_destination,
				stream->buffer, stream->buffer_size
			))
			return (false);
		ft_mem_copy(stream->buffer, ptr + written, size - written);
		stream->pos = size - written;
	}
	else if (!ft_buffered_ostream_flush(stream)
		|| !ft_ostream_write(
			stream->any_destination, ptr, size
		))
		return (false);
	return (true);
}

bool	ft_buffered_ostream_flush(t_buffered_ostream *stream)
{
	if (!ft_ostream_write(
			stream->any_destination,
			stream->buffer, stream->pos
		))
		return (false);
	stream->pos = 0;
	return (true);
}
