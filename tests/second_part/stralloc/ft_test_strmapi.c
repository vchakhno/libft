/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_test_strmapi.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchakhno <vchakhno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 00:17:53 by velimir           #+#    #+#             */
/*   Updated: 2022/10/17 17:31:39 by vchakhno         ###   ########.fr       */
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

static char	ft_toupper_functor(unsigned int i, char c)
{
	(void) i;
	if ('a' <= c && c <= 'z')
		return (c - 'a' + 'A');
	return (c);
}

static char	ft_cesar(unsigned int i, char c)
{
	(void) i;
	if ('a' <= c && c <= 'z')
		return ((c - 'a' + 3) % 26 + 'a');
	if ('A' <= c && c <= 'Z')
		return ((c - 'A' + 3) % 26 + 'A');
	return (c);
}

int	main(void)
{
	char	*mapped;

	mapped = ft_strmapi("Hello World!", ft_toupper_functor);
	assert(mapped);
	assert(ft_str_equal(mapped, "HELLO WORLD!"));
	free(mapped);
	mapped = ft_strmapi("Hello World!", ft_cesar);
	assert(mapped);
	assert(ft_str_equal(mapped, "Khoor Zruog!"));
	free(mapped);
	printf("ft_strmapi: OK\n");
}
