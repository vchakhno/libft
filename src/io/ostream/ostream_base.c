/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ostream_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchakhno <vchakhno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 18:32:15 by vchakhno          #+#    #+#             */
/*   Updated: 2023/05/18 09:14:13 by vchakhno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/io/ostream/ostream.h"

void	ft_ostream_base_init(t_ostream_base *stream, t_ostream_write write)
{
	stream->write = write;
	stream->ended = false;
}
