/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffered_ostream.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchakhno <vchakhno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 18:32:15 by vchakhno          #+#    #+#             */
/*   Updated: 2023/06/03 21:32:45 by vchakhno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/io/ostream.h"
#include "libft/data/mem.h"

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

	written = 0;
	while (size - written > stream->buffer_size - stream->pos)
	{
		ft_mem_copy(stream->buffer + stream->pos,
			ptr + written,
			stream->buffer_size - stream->pos);
		if (!ft_ostream_write(stream->any_destination,
				stream->buffer, stream->buffer_size))
			return (false);
		written += stream->buffer_size - stream->pos;
		stream->pos = 0;
	}
	ft_mem_copy(stream->buffer + stream->pos, ptr + written,
		size - written);
	stream->pos += size - written;
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
