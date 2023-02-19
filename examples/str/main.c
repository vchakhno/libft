/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchakhno <vchakhno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 22:13:40 by vchakhno          #+#    #+#             */
/*   Updated: 2023/02/19 00:41:00 by vchakhno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/text/str.h"
#include <stdio.h>
#include <stdlib.h>

void	ft_str_compare_example(void)
{
	t_str_slice	left;
	t_str_slice	right;

	left = ft_c_str_borrow("ComparisonA");
	right = ft_c_str_borrow("ComparisonB");
	printf("Comparing \"%.*s\" and \"%.*s\"\n",
		(int) left.len, left.c_str,
		(int) right.len, right.c_str);
	printf("Ascii difference: %d\n\n", ft_str_compare(&left, &right));
}

void	ft_str_equal_example(void)
{
	t_str_slice	left;
	t_str_slice	right;

	left = ft_c_str_borrow("Velimir");
	right = ft_c_str_borrow("Velimir");
	printf("Checking equality between \"%.*s\" and \"%.*s\"\n",
		(int) left.len, left.c_str,
		(int) right.len, right.c_str);
	printf("Equal: %s\n\n",
		ft_str_equal(&left, &right)[(char *[]){"false", "true"}]);
}

void	ft_str_find_char_example(void)
{
	t_str_slice	str;
	char		c;
	size_t		pos;

	str = ft_c_str_borrow("Velimir");
	c = 'm';
	printf("Searching char '%c' in string \"%.*s\"\n",
		c, (int) str.len, str.c_str);
	if (!ft_str_find_char(&str, c, &pos))
	{
		printf("The character was not found.\n\n");
		return ;
	}
	printf("Found in position: %d\n\n", (int) pos);
}

int	main(void)
{
	ft_str_compare_example();
	ft_str_equal_example();
	ft_str_find_char_example();
}
