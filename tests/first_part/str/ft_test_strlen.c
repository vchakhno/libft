/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_test_strlen.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchakhno <vchakhno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 21:32:58 by velimir           #+#    #+#             */
/*   Updated: 2022/10/16 03:29:51 by vchakhno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <assert.h>
#include <stdio.h>

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	main(void)
{
	assert(ft_strlen("") == 0);
	assert(ft_strlen(" ") == 1);
	assert(ft_strlen("1") == 1);
	assert(ft_strlen("a") == 1);
	assert(ft_strlen("123") == 3);
	assert(ft_strlen("Hello World") == 11);
	printf("ft_strlen: OK\n");
}
