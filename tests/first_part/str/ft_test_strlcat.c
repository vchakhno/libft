/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_test_strlcat.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchakhno <vchakhno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 23:07:21 by velimir           #+#    #+#             */
/*   Updated: 2022/10/16 04:02:56 by vchakhno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <assert.h>
#include <stdio.h>

int	main(void)
{
	char	dest[40];
	size_t	len;

	dest[0] = '\0';
	dest[10] = 'a';
	dest[17] = 'a';
	len = ft_strlcat(dest, "Bienvenue", 40);
	assert(len == 9);
	assert(dest[0] == 'B');
	assert(dest[4] == 'v');
	assert(dest[8] == 'e');
	assert(dest[9] == '\0');
	len = ft_strlcat(dest, " Velimir", 40);
	assert(len == 17);
	assert(dest[9] == ' ');
	assert(dest[10] == 'V');
	assert(dest[16] == 'r');
	assert(dest[17] == '\0');
	printf("ft_strlcat: OK\n");
}
