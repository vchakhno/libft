/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rsplit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchakhno <vchakhno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 13:04:46 by vchakhno          #+#    #+#             */
/*   Updated: 2023/06/03 20:48:26 by vchakhno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/data/str.h"
#include "libft/data/iterator.h"
#include "libft/data/mem.h"

bool	ft_str_rsplit_iterator_next(t_str_split_iterator *iterator,
			t_borrowed_str *dest);

void	ft_str_rsplit_by_str(
	t_any_str *any_str, t_any_str *any_delim, t_str_split_iterator *iterator
) {
	ft_iterator_base_init(&iterator->base, ft_str_rsplit_iterator_next);
	iterator->remaining = *(t_borrowed_str *)any_str;
	iterator->delim = *(t_borrowed_str *)any_delim;
}

void	ft_str_rsplit_by_c_str(
	t_any_str *any_str, char *delim, t_str_split_iterator *iterator
) {
	ft_iterator_base_init(&iterator->base, ft_str_rsplit_iterator_next);
	iterator->remaining = *(t_borrowed_str *)any_str;
	iterator->delim = ft_c_str_borrow(delim);
}

bool	ft_str_rsplit_iterator_next(
	t_str_split_iterator *iterator, t_borrowed_str *dest
) {
	t_u32	index;

	if (iterator->remaining.len == 0)
		return (false);
	if (ft_str_rfind_str(&iterator->remaining, &iterator->delim, &index))
	{
		dest->c_str = iterator->remaining.c_str + index + iterator->delim.len;
		dest->len = iterator->remaining.len - index - iterator->delim.len;
		iterator->remaining.len = index;
	}
	else
	{
		*dest = iterator->remaining;
		iterator->remaining.len = 0;
	}
	return (true);
}
