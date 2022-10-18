/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_test_strncmp.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchakhno <vchakhno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 22:38:37 by velimir           #+#    #+#             */
/*   Updated: 2022/10/16 03:33:59 by vchakhno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <assert.h>
#include <stdio.h>

int	main(void)
{
	assert(ft_strncmp("Bonjour", "Bonsoir", 0) == 0);
	assert(ft_strncmp("Bonjour", "Bonsoir", 3) == 0);
	assert(ft_strncmp("Bonjour", "Bonsoir", 7) == -9);
	assert(ft_strncmp("Bonjour", "Bonsoir", 100) == -9);
	assert(ft_strncmp("Bonjour", "", 0) == 0);
	assert(ft_strncmp("Bonjour", "", 1) == 66);
	printf("ft_strncmp: OK\n");
}
