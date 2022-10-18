/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchakhno <vchakhno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 00:17:53 by velimir           #+#    #+#             */
/*   Updated: 2022/10/17 17:52:18 by vchakhno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

static int	ft_abs(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

void	ft_putnbr_fd(int n, int fd)
{
	int	first_part;

	if (n < 0)
		ft_putchar_fd('-', fd);
	first_part = ft_abs(n / 10);
	if (first_part)
		ft_putnbr_fd(first_part, fd);
	ft_putchar_fd(ft_abs(n % 10) + '0', fd);
}
