/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array_ostream.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchakhno <vchakhno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 15:33:04 by vchakhno          #+#    #+#             */
/*   Updated: 2023/03/06 14:33:39 by vchakhno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/ostream/ostream.h"
#include "libft/mem/mem.h"
#include "libft/math.h"

void	ft_array_ostream_init(t_array_ostream *stream,
			void *array, size_t elem_size, size_t array_capacity)
{
	ft_ostream_base_init(&stream->base, ft_array_ostream_write);
	stream->array = array;
	stream->elem_size = elem_size;
	stream->pos = 0;
	stream->capacity = array_capacity;
}

size_t	ft_array_ostream_write(t_array_ostream *stream,
	void *elems, size_t count)
{
	count = ft_math_min_size_t(count, stream->capacity - stream->pos);
	ft_mem_copy(stream->array + stream->pos * stream->elem_size,
		elems, count * stream->elem_size);
	stream->pos += count;
	return (count);
}
