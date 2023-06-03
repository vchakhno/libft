/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fd_ostream.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchakhno <vchakhno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 18:32:15 by vchakhno          #+#    #+#             */
/*   Updated: 2023/06/03 21:08:45 by vchakhno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/io/ostream.h"
#include "libft/io/printing.h"

void	ft_fd_ostream_init(t_fd_ostream *stream, int fd)
{
	ft_ostream_base_init(&stream->base, ft_fd_ostream_write);
	stream->fd = fd;
}

bool	ft_fd_ostream_write(t_fd_ostream *stream, char *str, t_u32 n)
{
	return (ft_safe_write(stream->fd, str, n) == n);
}
