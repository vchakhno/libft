/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_test_str_splitting.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchakhno <vchakhno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 22:13:40 by vchakhno          #+#    #+#             */
/*   Updated: 2023/05/03 16:41:00 by vchakhno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/str/str.h"
#include "libft/iterator/iterator.h"
#include <stdio.h>

void	ft_test_str_split(void)
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

void	ft_test_str_rsplit(void)
{
	t_borrowed_str			sentence;
	t_borrowed_str			word;
	t_str_split_iterator	iterator;

	sentence = ft_c_str_borrow("Bonjour Vélimir, comment ça va ?");
	ft_str_rsplit_by_c_str(&sentence, " ", &iterator);
	while (ft_iterator_next(&iterator, &word))
	{
		printf("Word: %.*s\n", (int) word.len, word.c_str);
	}
	printf("\n");
}

void	ft_test_str_splitting(void)
{
	ft_test_str_split();
	ft_test_str_rsplit();
}
