/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ostream.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchakhno <vchakhno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 18:32:15 by vchakhno          #+#    #+#             */
/*   Updated: 2023/05/04 12:10:55 by vchakhno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/ostream/ostream_internals.h"
#include "libft/str/str_internals.h"

bool	ft_ostream_has_ended(t_any_ostream *stream)
{
	return (stream->ended);
}

t_u32	ft_ostream_write(t_any_ostream *stream, void *elems, t_u32 count)
{
	t_u32	consumed;

	consumed = stream->write(stream, elems, count);
	if (consumed < count)
		stream->ended = true;
	return (consumed);
}
