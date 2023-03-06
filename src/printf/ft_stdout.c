/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stdout.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchakhno <vchakhno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 04:30:22 by vchakhno          #+#    #+#             */
/*   Updated: 2023/03/06 16:18:01 by vchakhno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/printf.h"
#include "libft/ostream/ostream.h"
#include <unistd.h>

#define FT_STDOUT_BUFFER_SIZE	1024

__attribute__((constructor))
static void	ft_init_stdout(void)
{
	static t_fd_ostream	raw_out;
	static char			buffer[FT_STDOUT_BUFFER_SIZE];

	ft_fd_ostream_init(&raw_out, STDOUT_FILENO);
	ft_buffered_ostream_init(ft_stdout(),
		buffer, FT_STDOUT_BUFFER_SIZE, &raw_out);
}

__attribute__((destructor))
static void	ft_flush_stdout(void)
{
	ft_buffered_ostream_flush(ft_stdout());
}

t_buffered_ostream	*ft_stdout(void)
{
	static t_buffered_ostream	buffered_out;

	return (&buffered_out);
}
