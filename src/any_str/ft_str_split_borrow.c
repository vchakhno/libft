/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_split_borrow.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchakhno <vchakhno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 05:02:13 by vchakhno          #+#    #+#             */
/*   Updated: 2023/01/30 08:03:22 by vchakhno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_str.h"
#include "libft_char.h"
#include "libft_mem.h"
#include "libft_c_str.h"
#include <stdlib.h>

static size_t	ft_skip_delim(const t_str_slice *str, size_t current)
{
	size_t	i;

	i = 0;
	while (current + i < str->len && ft_char_is_blank(str->c_str[current + i]))
		i++;
	return (i);
}

static size_t	ft_borrow_word(const t_str_slice *str,
	size_t current, t_str_slice *dest)
{
	size_t	i;

	i = 0;
	while (current + i < str->len
		&& !ft_char_is_blank(str->c_str[current + i]))
		i++;
	dest->len = i;
	dest->c_str = str->c_str + current;
	return (i);
}

static size_t	ft_count_words(const t_str_slice *str)
{
	size_t	i;
	size_t	nb_words;

	i = 0;
	nb_words = 0;
	while (i < str->len)
	{
		if (!ft_char_is_blank(str->c_str[i])
			&& (i == 0 || ft_char_is_blank(str->c_str[i - 1])))
			nb_words++;
		i++;
	}
	return (nb_words);
}

bool	ft_str_split_borrow(const void *str, t_str_slice_array *split)
{
	size_t		str_i;
	size_t		split_i;
	t_str_slice	*to_split;

	to_split = (t_str_slice *) str;
	split->size = ft_count_words(to_split);
	if (!ft_mem_malloc(&split->strs, sizeof(t_str) * split->size))
		return (false);
	str_i = 0;
	split_i = 0;
	while (split_i < split->size)
	{
		str_i += ft_skip_delim(to_split, str_i);
		str_i += ft_borrow_word(to_split, str_i, split->strs + split_i);
		split_i++;
	}
	return (true);
}
