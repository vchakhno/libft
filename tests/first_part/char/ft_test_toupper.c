/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_test_toupper.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchakhno <vchakhno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 21:39:46 by velimir           #+#    #+#             */
/*   Updated: 2022/10/15 23:07:15 by vchakhno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <assert.h>
#include <stdio.h>

int	main(void)
{
	assert(ft_toupper('a') == 'A');
	assert(ft_toupper('h') == 'H');
	assert(ft_toupper('x') == 'X');
	assert(ft_toupper('z') == 'Z');
	assert(ft_toupper('A') == 'A');
	assert(ft_toupper('H') == 'H');
	assert(ft_toupper('X') == 'X');
	assert(ft_toupper('Z') == 'Z');
	assert(ft_toupper('1') == '1');
	assert(ft_toupper('4') == '4');
	assert(ft_toupper('6') == '6');
	assert(ft_toupper('9') == '9');
	assert(ft_toupper('/') == '/');
	assert(ft_toupper(' ') == ' ');
	printf("ft_toupper: OK\n");
}
