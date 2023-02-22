/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_split.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchakhno <vchakhno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 13:04:46 by vchakhno          #+#    #+#             */
/*   Updated: 2023/02/22 05:09:27 by vchakhno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/str/str_internal_types.h"
#include "libft/str/str.h"
#include "libft/iterator/iterator.h"
#include <stdbool.h>

bool	ft_str_split_iterator_next(t_str_split_iterator *iterator,
			t_borrowed_str *dest);

void	ft_str_split_by_str(t_any_str *str, t_any_str *delim,
	t_str_split_iterator *iterator)
{
	ft_iterator_base_init(&iterator->base, ft_str_split_iterator_next);
	iterator->haystack = *str;
	iterator->delim = *delim;
	iterator->pos = 0;
}

void	ft_str_split_by_c_str(t_any_str *str, char *delim,
	t_str_split_iterator *iterator)
{
	ft_iterator_base_init(&iterator->base, ft_str_split_iterator_next);
	iterator->haystack = *str;
	iterator->delim = ft_c_str_borrow(delim);
	iterator->pos = 0;
}

bool	ft_str_split_iterator_next(t_str_split_iterator *iterator,
	t_borrowed_str *dest)
{
	t_borrowed_str	next_word;

	if (iterator->pos == iterator->haystack.len)
		return (false);
	next_word = ft_str_borrow_slice__unchecked(&iterator->haystack,
			iterator->pos, iterator->haystack.len - iterator->pos);
	if (ft_str_find_str(&next_word, &iterator->delim, &next_word.len))
		iterator->pos += iterator->delim.len;
	iterator->pos += next_word.len;
	*dest = next_word;
	return (true);
}
