/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_test_isascii.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchakhno <vchakhno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 21:39:46 by velimir           #+#    #+#             */
/*   Updated: 2022/10/15 23:13:04 by vchakhno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <assert.h>
#include <stdio.h>

int	main(void)
{
	assert(ft_isascii('\0'));
	assert(ft_isascii('a'));
	assert(ft_isascii('h'));
	assert(ft_isascii('x'));
	assert(ft_isascii('z'));
	assert(ft_isascii('A'));
	assert(ft_isascii('H'));
	assert(ft_isascii('X'));
	assert(ft_isascii('Z'));
	assert(ft_isascii('1'));
	assert(ft_isascii('4'));
	assert(ft_isascii('6'));
	assert(ft_isascii('9'));
	assert(ft_isascii('/'));
	assert(ft_isascii(' '));
	assert(ft_isascii('\t'));
	assert(ft_isascii('\n'));
	assert(ft_isascii('\x7F'));
	assert(!ft_isascii(-1));
	printf("ft_isascii: OK\n");
}
