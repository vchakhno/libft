/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_test_strtrim.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchakhno <vchakhno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 00:17:53 by velimir           #+#    #+#             */
/*   Updated: 2022/10/17 17:36:14 by vchakhno         ###   ########.fr       */
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
	char	*trimmed;

	trimmed = ft_strtrim("\ttrim this\n", " \t\n");
	assert(trimmed);
	assert(ft_str_equal(trimmed, "trim this"));
	free(trimmed);
	printf("ft_strtrim: OK\n");
}
