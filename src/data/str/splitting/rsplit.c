/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rsplit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchakhno <vchakhno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 13:04:46 by vchakhno          #+#    #+#             */
/*   Updated: 2023/10/14 08:07:03 by vchakhno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/data/str.h"
#include "libft/data/iter.h"
#include "libft/data/mem.h"

bool	ft_str_rsplit_iter_next(t_str_split_iter *iter, t_str *dest);

void	ft_str_rsplit_by_str(t_str str, t_str delim, t_str_split_iter *iter)
{
	iter->next = ft_str_rsplit_iter_next;
	iter->remaining = str;
	iter->delim = delim;
}

void	ft_str_rsplit_by_c_str(t_str str, char *delim, t_str_split_iter *iter)
{
	iter->next = ft_str_rsplit_iter_next;
	iter->remaining = str;
	iter->delim = ft_str_from_c_str(delim);
}

bool	ft_str_rsplit_iter_next(t_str_split_iter *iter, t_str *dest)
{
	t_u32	index;

	if (iter->remaining.len == 0)
		return (false);
	if (ft_str_rfind_str(iter->remaining, iter->delim, &index))
	{
		dest->c_str = iter->remaining.c_str + index + iter->delim.len;
		dest->len = iter->remaining.len - index - iter->delim.len;
		iter->remaining.len = index;
	}
	else
	{
		*dest = iter->remaining;
		iter->remaining.len = 0;
	}
	return (true);
}
