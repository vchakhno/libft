/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_rsplit.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchakhno <vchakhno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 13:04:46 by vchakhno          #+#    #+#             */
/*   Updated: 2023/02/22 06:54:20 by vchakhno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/str/str_internal_types.h"
#include "libft/str/str.h"
#include "libft/iterator/iterator.h"
#include <stdbool.h>

bool	ft_str_rsplit_iterator_next(t_str_rsplit_iterator *iterator,
			t_borrowed_str *dest);

void	ft_str_rsplit_by_str(t_any_str *str, t_any_str *delim,
	t_str_rsplit_iterator *iterator)
{
	ft_iterator_base_init(&iterator->base, ft_str_rsplit_iterator_next);
	iterator->haystack = *str;
	iterator->delim = *delim;
	iterator->pos = 0;
}

void	ft_str_rsplit_by_c_str(t_any_str *str, char *delim,
	t_str_rsplit_iterator *iterator)
{
	ft_iterator_base_init(&iterator->base, ft_str_rsplit_iterator_next);
	iterator->haystack = *str;
	iterator->delim = ft_c_str_borrow(delim);
	iterator->pos = 0;
}

// TODO:
//	Clean this function

bool	ft_str_rsplit_iterator_next(t_str_rsplit_iterator *iterator,
	t_borrowed_str *dest)
{
	t_borrowed_str	to_search;
	t_borrowed_str	word;
	size_t			index;

	if (iterator->pos == iterator->haystack.len)
		return (false);
	to_search = ft_str_borrow_slice__unchecked(&iterator->haystack,
			0, iterator->haystack.len - iterator->pos);
	if (ft_str_rfind_str(&to_search, &iterator->delim, &index))
		iterator->pos += iterator->delim.len;
	else
		index = (size_t) -1;
	word = ft_str_borrow_slice__unchecked(&iterator->haystack,
			index + iterator->delim.len,
			to_search.len - index - iterator->delim.len);
	iterator->pos += word.len;
	*dest = word;
	return (true);
}
