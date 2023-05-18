/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchakhno <vchakhno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 18:57:43 by vchakhno          #+#    #+#             */
/*   Updated: 2023/05/18 07:58:55 by vchakhno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/data/mem/mem.h"
#include <stdlib.h>
#include <stdio.h>

void	ft_mem_calloc_example(void)
{
	int	*array;

	if (!ft_mem_calloc(&array, 3, sizeof(int)))
	{
		printf("Allocation failed\n");
		return ;
	}
	array[0] = 5;
	array[1] = 6;
	array[2] = 7;
	printf("[%d, %d, %d]\n", array[0], array[1], array[2]);
	free(array);
}

int	main(void)
{
	ft_mem_calloc_example();
}
