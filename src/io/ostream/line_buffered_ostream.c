/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_buffered_ostream.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchakhno <vchakhno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 18:32:15 by vchakhno          #+#    #+#             */
/*   Updated: 2023/07/24 01:02:50 by vchakhno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/io/ostream.h"
#include "libft/data/mem.h"
#include "libft/data/str.h"

void	ft_line_buffered_ostream_init(
	t_buffered_ostream *stream,
	void *buffer, t_u32 buffer_size, t_any_ostream *any_destination
) {
	ft_ostream_base_init(&stream->base, ft_line_buffered_ostream_write);
	stream->buffer = buffer;
	stream->buffer_size = buffer_size;
	stream->pos = 0;
	stream->any_destination = any_destination;
}

bool	ft_line_buffered_ostream_write(
	t_buffered_ostream *stream, void *ptr, t_u32 size
) {
	t_borrowed_str	str;

	str = ft_borrowed_str_from_parts(ptr, size);
	if (!ft_str_contains_char(&str, '\n'))
		return (ft_buffered_ostream_write(stream, ptr, size));
	if (size <= stream->buffer_size - stream->pos)
	{
		ft_mem_copy(stream->buffer + stream->pos, ptr, size);
		stream->pos += size;
	}
	if (!ft_line_buffered_ostream_flush(stream))
		return (false);
	if (size > stream->buffer_size - stream->pos
		&& !ft_ostream_write(stream->any_destination, ptr, size))
		return (false);
	return (true);
}

bool	ft_line_buffered_ostream_flush(t_buffered_ostream *stream)
{
	return (ft_buffered_ostream_flush(stream));
}
