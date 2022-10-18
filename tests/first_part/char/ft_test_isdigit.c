/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_test_isdigit.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchakhno <vchakhno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 21:39:46 by velimir           #+#    #+#             */
/*   Updated: 2022/10/15 23:21:08 by vchakhno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <assert.h>
#include <stdio.h>

int	main(void)
{
	assert(ft_isdigit('1'));
	assert(ft_isdigit('4'));
	assert(ft_isdigit('6'));
	assert(ft_isdigit('9'));
	assert(!ft_isdigit('a'));
	assert(!ft_isdigit('h'));
	assert(!ft_isdigit('x'));
	assert(!ft_isdigit('z'));
	assert(!ft_isdigit('A'));
	assert(!ft_isdigit('H'));
	assert(!ft_isdigit('X'));
	assert(!ft_isdigit('Z'));
	assert(!ft_isdigit('/'));
	assert(!ft_isdigit(' '));
	assert(!ft_isdigit('\t'));
	assert(!ft_isdigit('\n'));
	assert(!ft_isdigit('\xFF'));
	printf("ft_isdigit: OK\n");
}
