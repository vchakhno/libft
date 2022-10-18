/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_test_strchr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchakhno <vchakhno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 22:19:16 by velimir           #+#    #+#             */
/*   Updated: 2022/10/16 03:43:21 by vchakhno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <assert.h>
#include <stdio.h>
#include <stddef.h>

int	main(void)
{
	char	*str;

	str = "banana";
	assert(ft_strchr(str, 'a') == str + 1);
	assert(ft_strchr(str, 'd') == NULL);
	assert(ft_strchr(str, '\0') == str + 6);
	printf("ft_strchr: OK\n");
	assert(ft_strrchr(str, 'a') == str + 5);
	assert(ft_strrchr(str, 'd') == NULL);
	assert(ft_strrchr(str, '\0') == str + 6);
	printf("ft_strrchr: OK\n");
}
