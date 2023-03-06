/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fixed_str_ostream.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchakhno <vchakhno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 18:59:11 by vchakhno          #+#    #+#             */
/*   Updated: 2023/03/06 14:28:33 by vchakhno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/ostream/ostream.h"
#include "libft/mem/mem.h"
#include "libft/math.h"

void	ft_fixed_str_ostream_init(t_fixed_str_ostream *stream,
	char *dest, size_t size)
{
	ft_ostream_base_init(&stream->base, ft_fixed_str_ostream_write);
	stream->dest = dest;
	stream->pos = 0;
	stream->size = size - 1;
}

size_t	ft_fixed_str_ostream_write(t_fixed_str_ostream *stream,
	char *str, size_t n)
{
	size_t	copy_size;

	copy_size = ft_math_min_size_t(n, stream->size - stream->pos);
	ft_mem_copy(&stream->dest[stream->pos], str, copy_size);
	stream->pos += copy_size;
	stream->dest[stream->pos] = '\0';
	return (copy_size);
}
