/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_test_memcpy.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchakhno <vchakhno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 16:33:30 by velimir           #+#    #+#             */
/*   Updated: 2022/10/16 18:25:50 by vchakhno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <assert.h>
#include <stdio.h>

int	main(void)
{
	unsigned int	a;
	unsigned int	b;

	a = 0x01020304;
	b = 0x04030201;
	ft_memcpy(&b, &a, 0);
	assert(b == 0x04030201);
	ft_memcpy(&b, &a, 1);
	assert(b == 0x04030204);
	b = 0x04030201;
	ft_memcpy(&b, &a, 2);
	assert(b == 0x04030304);
	b = 0x04030201;
	ft_memcpy(&b, &a, 3);
	assert(b == 0x04020304);
	b = 0x04030201;
	ft_memcpy(&b, &a, sizeof(int));
	assert(b == 0x01020304);
	printf("ft_memcpy: OK\n");
}
