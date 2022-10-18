/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_test_isalpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchakhno <vchakhno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 21:39:46 by velimir           #+#    #+#             */
/*   Updated: 2022/10/15 23:04:18 by vchakhno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <assert.h>
#include <stdio.h>

int	main(void)
{
	assert(ft_isalpha('a'));
	assert(ft_isalpha('h'));
	assert(ft_isalpha('x'));
	assert(ft_isalpha('z'));
	assert(ft_isalpha('A'));
	assert(ft_isalpha('H'));
	assert(ft_isalpha('X'));
	assert(ft_isalpha('Z'));
	assert(!ft_isalpha('1'));
	assert(!ft_isalpha('4'));
	assert(!ft_isalpha('6'));
	assert(!ft_isalpha('9'));
	assert(!ft_isalpha('/'));
	assert(!ft_isalpha(' '));
	assert(!ft_isalpha('\t'));
	assert(!ft_isalpha('\n'));
	assert(!ft_isalpha('\xFF'));
	printf("ft_isalpha: OK\n");
}
