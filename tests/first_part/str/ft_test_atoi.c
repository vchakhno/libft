/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_test_atoi.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchakhno <vchakhno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 19:18:09 by vchakhno          #+#    #+#             */
/*   Updated: 2022/10/16 04:01:44 by vchakhno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <assert.h>
#include <stdio.h>

static void	mass_assert(int size, char **strs, int *nums)
{
	int	i;

	i = 0;
	while (i < size)
	{
		assert(ft_atoi(strs[i]) == nums[i]);
		i++;
	}
}

int	main(void)
{
	mass_assert(3,
		(char *[]){"0", "1", "9"},
		(int []){0, 1, 9});
	mass_assert(6,
		(char *[]){"10", "51", "+42", "-0", "012", "-42"},
		(int []){10, 51, 42, 0, 12, -42});
	mass_assert(3,
		(char *[]){"2147483647", "+2147483647", "-2147483648"},
		(int []){2147483647, 2147483647, -2147483648});
	mass_assert(2,
		(char *[]){" \n-15", "\t\t+9"},
		(int []){-15, 9});
	mass_assert(2,
		(char *[]){"123b", "D123"},
		(int []){123, 0});
	mass_assert(3,
		(char *[]){"--3", "++3", "+-3"},
		(int []){0, 0, 0});
	mass_assert(2,
		(char *[]){" + 3", " - 3"},
		(int []){0, 0});
	printf("ft_atoi: OK\n");
}
