/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchakhno <vchakhno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 11:53:33 by vchakhno          #+#    #+#             */
/*   Updated: 2023/06/03 20:16:45 by vchakhno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/data/str/str.h"
#include "libft/arithmetic/fixed_types.h"
#include "libft/data/mem/mem.h"

bool	ft_str_find_char(t_any_str *any_haystack, char c, t_u32 *index)
{
	t_borrowed_str *const	haystack = any_haystack;
	t_u32					i;

	i = 0;
	while (i < haystack->len)
	{
		if (haystack->c_str[i] == c)
		{
			*index = i;
			return (true);
		}
		i++;
	}
	return (false);
}

bool	ft_str_find_str(
	t_any_str *any_haystack, t_any_str *any_needle, t_u32 *index
) {
	t_borrowed_str *const	haystack = any_haystack;
	t_borrowed_str *const	needle = any_needle;
	t_u32					i;

	i = 0;
	while (i + needle->len < haystack->len + 1)
	{
		if (ft_mem_equal(haystack->c_str + i, needle->c_str, needle->len))
		{
			*index = i;
			return (true);
		}
		i++;
	}
	return (false);
}

bool	ft_str_find_c_str(t_any_str *any_haystack, char *needle, t_u32 *index)
{
	t_borrowed_str *const	haystack = any_haystack;
	t_u32					needle_len;
	t_u32					i;

	needle_len = ft_c_str_len(needle);
	i = 0;
	while (i + needle_len < haystack->len + 1)
	{
		if (ft_mem_equal(haystack->c_str + i, needle, needle_len))
		{
			*index = i;
			return (true);
		}
		i++;
	}
	return (false);
}
