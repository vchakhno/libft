/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_test_strnstr.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchakhno <vchakhno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 00:17:53 by velimir           #+#    #+#             */
/*   Updated: 2022/10/16 03:45:43 by vchakhno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <assert.h>
#include <stdio.h>
#include <stddef.h>

int	main(void)
{
	const char	*str = "Foo Bar Baz";
	const char	*empty = "";

	assert(ft_strnstr(str, "Bar", 3) == NULL);
	assert(ft_strnstr(str + 4, "Bar", 3) == str + 4);
	assert(ft_strnstr(str + 3, "Bar", 3) == NULL);
	assert(ft_strnstr(str + 3, "Bar", 4) == str + 4);
	assert(ft_strnstr(str, "", 4) == str);
	assert(ft_strnstr(empty, "Bar", 4) == NULL);
	assert(ft_strnstr(empty, "", 4) == empty);
	printf("ft_strnstr: OK\n");
}
