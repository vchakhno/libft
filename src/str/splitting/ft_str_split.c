/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_split.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchakhno <vchakhno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 13:04:46 by vchakhno          #+#    #+#             */
/*   Updated: 2023/05/03 17:01:14 by vchakhno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/str/str_internals.h"
#include "libft/iterator/iterator.h"

bool	ft_str_split_iterator_next(t_str_split_iterator *iterator,
			t_borrowed_str *dest);

void	ft_str_split_by_str(t_any_str *str, t_any_str *delim,
	t_str_split_iterator *iterator)
{
	ft_iterator_base_init(&iterator->base, ft_str_split_iterator_next);
	iterator->remaining = *str;
	iterator->delim = *delim;
}

void	ft_str_split_by_c_str(t_any_str *str, char *delim,
	t_str_split_iterator *iterator)
{
	ft_iterator_base_init(&iterator->base, ft_str_split_iterator_next);
	iterator->remaining = *str;
	iterator->delim = ft_c_str_borrow(delim);
}

bool	ft_str_split_iterator_next(t_str_split_iterator *iterator,
	t_borrowed_str *dest)
{
	t_u32	index;

	if (iterator->remaining.len == 0)
		return (false);
	if (ft_str_find_str(&iterator->remaining, &iterator->delim, &index))
	{
		dest->c_str = iterator->remaining.c_str;
		dest->len = index;
		iterator->remaining.c_str += index + iterator->delim.len;
		iterator->remaining.len -= index + iterator->delim.len;
	}
	else
	{
		*dest = iterator->remaining;
		iterator->remaining.c_str += iterator->remaining.len;
		iterator->remaining.len = 0;
	}
	return (true);
}
