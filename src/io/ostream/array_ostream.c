/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_ostream.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchakhno <vchakhno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 15:33:04 by vchakhno          #+#    #+#             */
/*   Updated: 2023/06/03 20:47:49 by vchakhno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/io/ostream/ostream.h"
#include "libft/data/mem.h"
#include "libft/arithmetic/bounds.h"

void	ft_array_ostream_init(
	t_array_ostream *stream, void *array, t_u32 elem_size, t_u32 array_capacity
) {
	ft_ostream_base_init(&stream->base, ft_array_ostream_write);
	stream->array = array;
	stream->elem_size = elem_size;
	stream->pos = 0;
	stream->capacity = array_capacity;
}

bool	ft_array_ostream_write(
	t_array_ostream *stream, void *elems, t_u32 count
) {
	t_u32	capped_count;

	capped_count = ft_u32_min(count, stream->capacity - stream->pos);
	ft_mem_copy(stream->array + stream->pos * stream->elem_size,
		elems, capped_count * stream->elem_size);
	stream->pos += capped_count;
	return (capped_count == count);
}
