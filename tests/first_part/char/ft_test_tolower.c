/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_test_tolower.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchakhno <vchakhno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 21:39:46 by velimir           #+#    #+#             */
/*   Updated: 2022/10/15 23:06:57 by vchakhno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <assert.h>
#include <stdio.h>

int	main(void)
{
	assert(ft_tolower('a') == 'a');
	assert(ft_tolower('h') == 'h');
	assert(ft_tolower('x') == 'x');
	assert(ft_tolower('z') == 'z');
	assert(ft_tolower('A') == 'a');
	assert(ft_tolower('H') == 'h');
	assert(ft_tolower('X') == 'x');
	assert(ft_tolower('Z') == 'z');
	assert(ft_tolower('1') == '1');
	assert(ft_tolower('4') == '4');
	assert(ft_tolower('6') == '6');
	assert(ft_tolower('9') == '9');
	assert(ft_tolower('/') == '/');
	assert(ft_tolower(' ') == ' ');
	printf("ft_tolower: OK\n");
}
