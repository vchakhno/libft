/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rsplit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchakhno <vchakhno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 13:04:46 by vchakhno          #+#    #+#             */
/*   Updated: 2023/07/24 05:18:09 by vchakhno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/data/str.h"
#include "libft/data/iterator.h"
#include "libft/data/mem.h"

bool	ft_str_rsplit_iterator_next(t_str_split_iterator *iterator,
			t_str *dest);

void	ft_str_rsplit_by_str(
	t_str str, t_str delim, t_str_split_iterator *iterator
) {
	ft_iterator_base_init(&iterator->base, ft_str_rsplit_iterator_next);
	iterator->remaining = str;
	iterator->delim = delim;
}

void	ft_str_rsplit_by_c_str(
	t_str str, char *delim, t_str_split_iterator *iterator
) {
	ft_iterator_base_init(&iterator->base, ft_str_rsplit_iterator_next);
	iterator->remaining = str;
	iterator->delim = ft_str_from_c_str(delim);
}

bool	ft_str_rsplit_iterator_next(t_str_split_iterator *iterator, t_str *dest)
{
	t_u32	index;

	if (iterator->remaining.len == 0)
		return (false);
	if (ft_str_rfind_str(iterator->remaining, iterator->delim, &index))
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
