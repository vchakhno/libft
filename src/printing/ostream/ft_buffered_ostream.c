/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_buffered_ostream.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchakhno <vchakhno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 18:32:15 by vchakhno          #+#    #+#             */
/*   Updated: 2023/05/03 12:50:37 by vchakhno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/ostream/ostream.h"
#include "libft/mem/mem.h"

void	ft_buffered_ostream_init(
	t_buffered_ostream *stream,
	void *buffer, t_u32 buffer_size, t_any_ostream *destination
) {
	ft_ostream_base_init(&stream->base, ft_buffered_ostream_write);
	stream->buffer = buffer;
	stream->buffer_size = buffer_size;
	stream->pos = 0;
	stream->destination = destination;
}

t_u32	ft_buffered_ostream_write(
	t_buffered_ostream *stream, void *ptr, t_u32 size
) {
	t_u32	total_written;
	t_u32	last_written;

	total_written = 0;
	while (size - total_written > stream->buffer_size - stream->pos)
	{
		ft_mem_copy(stream->buffer + stream->pos,
			ptr + total_written,
			stream->buffer_size - stream->pos);
		last_written = ft_ostream_write(stream->destination,
				stream->buffer, stream->buffer_size);
		total_written += last_written;
		if (last_written < stream->buffer_size)
			return (total_written);
		stream->pos = 0;
	}
	ft_mem_copy(stream->buffer + stream->pos, ptr + total_written,
		size - total_written);
	stream->pos += size - total_written;
	return (size);
}

bool	ft_buffered_ostream_flush(t_buffered_ostream *stream)
{
	if (ft_ostream_write(
			stream->destination,
			stream->buffer, stream->pos
		) != stream->pos)
		return (false);
	stream->pos = 0;
	return (true);
}
