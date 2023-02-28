/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_test_str_comparison.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchakhno <vchakhno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 22:13:40 by vchakhno          #+#    #+#             */
/*   Updated: 2023/02/28 04:32:35 by vchakhno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/str/str.h"
#include <stdio.h>

void	ft_test_str_compare(void)
{
	t_str_slice	left;
	t_str_slice	right;

	left = ft_c_str_borrow("ComparisonA");
	right = ft_c_str_borrow("ComparisonB");
	printf("Comparing \"%.*s\" and \"%.*s\"\n",
		(int) left.len, left.c_str,
		(int) right.len, right.c_str);
	printf("Ascii difference: %d\n\n", ft_str_compare_str(&left, &right));
}

void	ft_test_str_equal(void)
{
	t_str_slice	left;
	t_str_slice	right;

	left = ft_c_str_borrow("Velimir");
	right = ft_c_str_borrow("Velimir");
	printf("Checking equality between \"%.*s\" and \"%.*s\"\n",
		(int) left.len, left.c_str,
		(int) right.len, right.c_str);
	printf("Equal: %s\n\n",
		ft_str_equal_str(&left, &right)[(char *[]){"false", "true"}]);
}

void	ft_test_str_comparison(void)
{
	ft_test_str_compare();
	ft_test_str_equal();
}
