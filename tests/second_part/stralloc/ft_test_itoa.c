/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_test_itoa.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchakhno <vchakhno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 00:17:53 by velimir           #+#    #+#             */
/*   Updated: 2022/10/17 17:08:42 by vchakhno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

static bool	ft_str_equal(const char *str1, const char *str2)
{
	int	i;

	i = 0;
	while (str1[i] || str2[i])
	{
		if (str1[i] != str2[i])
			return (false);
		i++;
	}
	return (true);
}

int	main(void)
{
	char	*str;

	str = ft_itoa(0);
	assert(str);
	assert(ft_str_equal(str, "0"));
	free(str);
	str = ft_itoa(-42);
	assert(str);
	assert(ft_str_equal(str, "-42"));
	free(str);
	str = ft_itoa(2147483647);
	assert(str);
	assert(ft_str_equal(str, "2147483647"));
	free(str);
	str = ft_itoa(-2147483648);
	assert(str);
	assert(ft_str_equal(str, "-2147483648"));
	free(str);
	printf("ft_itoa: OK\n");
}
