/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ostream.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchakhno <vchakhno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 18:32:15 by vchakhno          #+#    #+#             */
/*   Updated: 2023/03/06 14:33:23 by vchakhno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/str/str_internal_types.h"
#include "libft/str/str.h"
#include "libft/ostream/ostream_internal_types.h"
#include "libft/ostream/ostream.h"

bool	ft_ostream_has_ended(t_any_ostream *stream)
{
	return (stream->ended);
}

size_t	ft_ostream_write(t_any_ostream *stream, void *elems, size_t count)
{
	size_t	consumed;

	consumed = stream->write(stream, elems, count);
	if (consumed < count)
		stream->ended = true;
	return (consumed);
}

size_t	ft_ostream_write_c_str(t_any_ostream *stream, char *c_str)
{
	return (ft_ostream_write(stream, c_str, ft_c_str_len(c_str)));
}

size_t	ft_ostream_write_str(t_any_ostream *stream, t_any_str *str)
{
	return (ft_ostream_write(stream, str->c_str, str->len));
}
