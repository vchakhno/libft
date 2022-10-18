/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_test_split.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchakhno <vchakhno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 00:17:53 by velimir           #+#    #+#             */
/*   Updated: 2022/10/17 17:19:10 by vchakhno         ###   ########.fr       */
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
	char	**words;
	size_t	i;

	words = ft_split(",,,123,,45,6,", ',');
	assert(words);
	assert(ft_str_equal(words[0], "123"));
	assert(ft_str_equal(words[1], "45"));
	assert(ft_str_equal(words[2], "6"));
	assert(!words[3]);
	i = 0;
	while (i < 3)
	{
		free(words[i]);
		i++;
	}
	free(words);
	words = ft_split("", ',');
	assert(words);
	assert(!words[0]);
	free(words);
	printf("ft_split: OK\n");
}
