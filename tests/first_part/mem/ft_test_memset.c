/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_test_memset.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchakhno <vchakhno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 15:37:35 by velimir           #+#    #+#             */
/*   Updated: 2022/10/16 02:47:52 by vchakhno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <assert.h>
#include <stdio.h>

int	main(void)
{
	unsigned int	n;
	unsigned int	*p;

	n = 0xAFAFAFAF;
	p = (unsigned int *) ft_memset(&n, 0xBB, 0);
	assert(p == &n);
	assert(n == 0xAFAFAFAF);
	n = 0xAFAFAFAF;
	p = (unsigned int *) ft_memset(&n, 0xBB, 1);
	assert(p == &n);
	assert(n == 0xAFAFAFBB);
	n = 0xAFAFAFAF;
	p = (unsigned int *) ft_memset(&n, 0xBB, 2);
	assert(p == &n);
	assert(n == 0xAFAFBBBB);
	n = 0xAFAFAFAF;
	p = (unsigned int *) ft_memset(&n, 0xBB, 3);
	assert(p == &n);
	assert(n == 0xAFBBBBBB);
	n = 0xAFAFAFAF;
	p = (unsigned int *) ft_memset(&n, 0xBB, sizeof(int));
	assert(p == &n);
	assert(n == 0xBBBBBBBB);
	printf("ft_memset: OK\n");
}
