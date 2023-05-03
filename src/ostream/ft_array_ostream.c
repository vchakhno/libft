/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array_ostream.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchakhno <vchakhno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 15:33:04 by vchakhno          #+#    #+#             */
/*   Updated: 2023/05/03 12:49:51 by vchakhno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/ostream/ostream.h"
#include "libft/mem/mem.h"
#include "libft/bounds.h"

void	ft_array_ostream_init(
	t_array_ostream *stream, void *array, t_u32 elem_size, t_u32 array_capacity
) {
	ft_ostream_base_init(&stream->base, ft_array_ostream_write);
	stream->array = array;
	stream->elem_size = elem_size;
	stream->pos = 0;
	stream->capacity = array_capacity;
}

t_u32	ft_array_ostream_write(
	t_array_ostream *stream, void *elems, t_u32 count
) {
	count = ft_u32_min(count, stream->capacity - stream->pos);
	ft_mem_copy(stream->array + stream->pos * stream->elem_size,
		elems, count * stream->elem_size);
	stream->pos += count;
	return (count);
}
