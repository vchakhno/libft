/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchakhno <vchakhno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 22:13:40 by vchakhno          #+#    #+#             */
/*   Updated: 2023/02/22 10:31:05 by vchakhno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/str/str.h"
#include "libft/iterator/iterator.h"
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
	printf("Ascii difference: %d\n\n", ft_str_compare_str(&left, &right));
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
		ft_str_equal_str(&left, &right)[(char *[]){"false", "true"}]);
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

void	ft_str_split_example(void)
{
	t_borrowed_str			sentence;
	t_borrowed_str			word;
	t_str_split_iterator	iterator;

	sentence = ft_c_str_borrow("Bonjour Vélimir, comment ça va ?");
	ft_str_split_by_c_str(&sentence, " ", &iterator);
	while (ft_iterator_next(&iterator, &word))
	{
		printf("Word: %.*s\n", (int) word.len, word.c_str);
	}
	printf("\n");
}

void	ft_str_rsplit_example(void)
{
	t_borrowed_str			sentence;
	t_borrowed_str			word;
	t_str_rsplit_iterator	iterator;

	sentence = ft_c_str_borrow("Bonjour Vélimir, comment ça va ?");
	ft_str_rsplit_by_c_str(&sentence, " ", &iterator);
	while (ft_iterator_next(&iterator, &word))
	{
		printf("Word: %.*s\n", (int) word.len, word.c_str);
	}
	printf("\n");
}

void	ft_str_insert_example(void)
{
	t_allocated_str	str;

	if (!ft_str_dup_c_str(&str, "Bonjour, comment ça va ?"))
		return ;
	ft_str_insert_c_str(&str, 7, " Vélimir");
	printf("%.*s\n", (int) str.len, str.c_str);
	ft_str_free(&str);
}

int	main(void)
{
	// ft_str_compare_example();
	// ft_str_equal_example();
	// ft_str_find_char_example();
	// ft_str_split_example();
	// ft_str_rsplit_example();
	ft_str_insert_example();
}
