/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_test_calloc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchakhno <vchakhno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 15:37:35 by velimir           #+#    #+#             */
/*   Updated: 2022/10/16 00:20:30 by vchakhno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <stdint.h>

int	main(void)
{
	int	*arr;

	arr = ft_calloc(3, sizeof(int));
	if (!arr)
		return (0);
	assert(arr[0] == 0);
	assert(arr[1] == 0);
	assert(arr[2] == 0);
	free(arr);
	arr = ft_calloc(SIZE_MAX, SIZE_MAX);
	assert(arr == NULL);
	printf("ft_calloc: OK\n");
}
