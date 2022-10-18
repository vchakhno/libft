/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_test_memchr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchakhno <vchakhno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 19:14:45 by velimir           #+#    #+#             */
/*   Updated: 2022/10/16 00:04:49 by vchakhno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

int	main(void)
{
	const char	*msg[] = {
		"Bonjour", "je", "viens", "en", "paix"
	};
	int			i;

	i = 0;
	while (i < 5)
	{
		assert(
			(char *)ft_memchr((char *) msg[i], '\0', 10)
			== msg[i] + ft_strlen(msg[i])
			);
		i++;
	}
	assert((char *)ft_memchr((char *) msg[0], 'j', 10) == msg[0] + 3);
	printf("ft_memchr: OK\n");
}
