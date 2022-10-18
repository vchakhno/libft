/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_test_memcmp.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchakhno <vchakhno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 19:28:33 by velimir           #+#    #+#             */
/*   Updated: 2022/10/16 02:33:58 by vchakhno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <assert.h>
#include <stdio.h>

int	main(void)
{
	int	a;
	int	b;

	a = 0x1;
	b = 0x2;
	assert(ft_memcmp(&a, &b, 0) == 0);
	assert(ft_memcmp(&a, &b, sizeof(int)) == -1);
	a = 0x200;
	b = 0x100;
	assert(ft_memcmp(&a, &b, sizeof(int)) == 1);
	a = 0xAFAFAFAF;
	b = 0xAFAFAFAF;
	assert(ft_memcmp(&a, &b, sizeof(int)) == 0);
	printf("ft_memcmp: OK\n");
}
