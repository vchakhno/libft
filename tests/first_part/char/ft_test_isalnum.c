/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_test_isalnum.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchakhno <vchakhno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 21:39:46 by velimir           #+#    #+#             */
/*   Updated: 2022/10/16 18:25:18 by vchakhno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <assert.h>
#include <stdio.h>

int	main(void)
{
	assert(ft_isalnum('a'));
	assert(ft_isalnum('h'));
	assert(ft_isalnum('x'));
	assert(ft_isalnum('z'));
	assert(ft_isalnum('A'));
	assert(ft_isalnum('H'));
	assert(ft_isalnum('X'));
	assert(ft_isalnum('Z'));
	assert(ft_isalnum('1'));
	assert(ft_isalnum('4'));
	assert(ft_isalnum('6'));
	assert(ft_isalnum('9'));
	assert(!ft_isalnum('/'));
	assert(!ft_isalnum(' '));
	assert(!ft_isalnum('\t'));
	assert(!ft_isalnum('\n'));
	assert(!ft_isalnum('\xFF'));
	printf("ft_isalnum: OK\n");
}
