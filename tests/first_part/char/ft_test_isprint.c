/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_test_isprint.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchakhno <vchakhno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 21:39:46 by velimir           #+#    #+#             */
/*   Updated: 2022/10/15 23:06:47 by vchakhno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <assert.h>
#include <stdio.h>

int	main(void)
{
	assert(ft_isprint('a'));
	assert(ft_isprint('h'));
	assert(ft_isprint('x'));
	assert(ft_isprint('z'));
	assert(ft_isprint('A'));
	assert(ft_isprint('H'));
	assert(ft_isprint('X'));
	assert(ft_isprint('Z'));
	assert(ft_isprint('1'));
	assert(ft_isprint('4'));
	assert(ft_isprint('6'));
	assert(ft_isprint('9'));
	assert(ft_isprint('/'));
	assert(ft_isprint(' '));
	assert(!ft_isprint('\t'));
	assert(!ft_isprint('\n'));
	assert(!ft_isprint('\xFF'));
	printf("ft_isprint: OK\n");
}
