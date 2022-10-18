/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_test_memccpy.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchakhno <vchakhno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 16:33:30 by velimir           #+#    #+#             */
/*   Updated: 2022/10/16 00:19:58 by vchakhno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <assert.h>
#include <stdio.h>

int	main(void)
{
	unsigned int	src;
	unsigned int	dest;
	char			*p;

	src = 0x00004200;
	dest = 0xAFAFAFAF;
	p = (char *) ft_memccpy(&dest, &src, 0x42, sizeof(int));
	assert(dest == 0xAFAF4200);
	assert(p == (char *) &dest + 2);
	printf("ft_memccpy: OK\n");
}
