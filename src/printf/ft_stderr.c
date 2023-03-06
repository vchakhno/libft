/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stderr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchakhno <vchakhno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 04:30:22 by vchakhno          #+#    #+#             */
/*   Updated: 2023/03/06 16:14:25 by vchakhno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/printf.h"
#include "libft/ostream/ostream.h"
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
