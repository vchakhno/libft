/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fixed_str_ostream.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchakhno <vchakhno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 18:59:11 by vchakhno          #+#    #+#             */
/*   Updated: 2023/06/03 20:47:49 by vchakhno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/io/ostream/ostream.h"
#include "libft/data/mem.h"
#include "libft/arithmetic/bounds.h"

void	ft_fixed_str_ostream_init(
	t_fixed_str_ostream *stream, char *dest, t_u32 size
) {
	ft_ostream_base_init(&stream->base, ft_fixed_str_ostream_write);
	stream->dest = dest;
	stream->pos = 0;
	stream->size = size - 1;
}

bool	ft_fixed_str_ostream_write(
	t_fixed_str_ostream *stream, char *str, t_u32 n
) {
	t_u32	copy_size;

	copy_size = ft_u32_min(n, stream->size - stream->pos);
	ft_mem_copy(&stream->dest[stream->pos], str, copy_size);
	stream->pos += copy_size;
	stream->dest[stream->pos] = '\0';
	return (copy_size == n);
}
