/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_test_memmove.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchakhno <vchakhno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 17:23:44 by velimir           #+#    #+#             */
/*   Updated: 2022/10/16 03:03:15 by vchakhno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <assert.h>
#include <stdio.h>

int	main(void)
{
	int	*arr;

	arr = (int []){1, 2, 3, 0, 0};
	ft_memmove(arr + 2, arr, sizeof(int) * 3);
	assert(arr[2] == 1);
	assert(arr[3] == 2);
	assert(arr[4] == 3);
	arr = (int []){0, 0, 1, 2, 3};
	ft_memmove(arr, arr + 2, sizeof(int) * 3);
	assert(arr[0] == 1);
	assert(arr[1] == 2);
	assert(arr[2] == 3);
	printf("ft_memove: OK\n");
}
