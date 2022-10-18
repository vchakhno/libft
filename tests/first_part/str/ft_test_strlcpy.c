/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_test_strlcpy.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchakhno <vchakhno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 22:56:41 by velimir           #+#    #+#             */
/*   Updated: 2022/10/16 04:03:26 by vchakhno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <assert.h>
#include <stdio.h>

int	main(void)
{
	char	*src;
	char	dest[40];
	int		len;

	src = "Bienvenue Velimir";
	dest[0] = 'a';
	dest[17] = 'a';
	len = ft_strlcpy(dest, src, 0);
	assert(len == 17);
	assert(dest[0] == 'a');
	len = ft_strlcpy(dest, src, 40);
	assert(len == 17);
	assert(dest[0] == 'B');
	assert(dest[9] == ' ');
	assert(dest[10] == 'V');
	assert(dest[17] == '\0');
	printf("ft_strlcpy: OK\n");
}
