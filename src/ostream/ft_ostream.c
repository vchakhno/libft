/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ostream.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchakhno <vchakhno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 18:32:15 by vchakhno          #+#    #+#             */
/*   Updated: 2023/05/03 12:53:32 by vchakhno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/str/str_internal_types.h"
#include "libft/str/str.h"
#include "libft/ostream/ostream_internals.h"

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

t_u32	ft_ostream_write_c_str(t_any_ostream *stream, char *c_str)
{
	return (ft_ostream_write(stream, c_str, ft_c_str_len(c_str)));
}

t_u32	ft_ostream_write_str(t_any_ostream *stream, t_any_str *str)
{
	return (ft_ostream_write(stream, str->c_str, str->len));
}
