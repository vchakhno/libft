/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stderr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchakhno <vchakhno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 04:30:22 by vchakhno          #+#    #+#             */
/*   Updated: 2023/05/18 07:43:16 by vchakhno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/io/printing/printf.h"
#include "libft/io/printing/ostream/ostream.h"
#include <unistd.h>

__attribute__((constructor))
static void	ft_init_stderr(void)
{
	ft_fd_ostream_init(ft_stderr(), STDERR_FILENO);
}

t_fd_ostream	*ft_stderr(void)
{
	static t_fd_ostream	raw_err;

	return (&raw_err);
}
