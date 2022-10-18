/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_test_bzero.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchakhno <vchakhno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 15:37:35 by velimir           #+#    #+#             */
/*   Updated: 2022/10/16 00:06:05 by vchakhno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <assert.h>
#include <stdio.h>

int	main(void)
{
	unsigned int	n;

	n = 0xAFAFAFAF;
	ft_bzero(&n, 0);
	assert(n == 0xAFAFAFAF);
	ft_bzero(&n, 1);
	assert(n == 0xAFAFAF00);
	n = 0xAFAFAFAF;
	ft_bzero(&n, 2);
	assert(n == 0xAFAF0000);
	n = 0xAFAFAFAF;
	ft_bzero(&n, sizeof(int));
	assert(n == 0);
	printf("ft_bzero: OK\n");
}
