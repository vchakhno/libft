/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_test_putnbr_fd.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchakhno <vchakhno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 00:17:53 by velimir           #+#    #+#             */
/*   Updated: 2022/10/17 03:52:00 by vchakhno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <assert.h>
#include <stdio.h>
#include <limits.h>

int	main(void)
{
	ft_putnbr_fd(0, 1);
	ft_putnbr_fd(42, 1);
	ft_putnbr_fd(INT_MAX, 1);
	ft_putnbr_fd(INT_MIN, 1);
	ft_putnbr_fd(0, 2);
	ft_putnbr_fd(-54, 2);
	ft_putnbr_fd(INT_MAX, 2);
	ft_putnbr_fd(INT_MIN, 2);
}
