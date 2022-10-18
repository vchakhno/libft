/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_test_strdup.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchakhno <vchakhno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 15:37:35 by velimir           #+#    #+#             */
/*   Updated: 2022/10/16 03:45:08 by vchakhno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

int	main(void)
{
	const char	*str = "Hello";
	char		*dup;

	dup = ft_strdup(str);
	assert(dup != str);
	assert(dup[0] == str[0]);
	assert(dup[1] == str[1]);
	assert(dup[2] == str[2]);
	assert(dup[3] == str[3]);
	assert(dup[4] == str[4]);
	assert(dup[5] == str[5]);
	free(dup);
	printf("ft_strdup: OK\n");
}
