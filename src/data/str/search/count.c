/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchakhno <vchakhno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 11:53:33 by vchakhno          #+#    #+#             */
/*   Updated: 2023/06/03 20:47:59 by vchakhno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/data/str.h"
#include "libft/arithmetic/fixed_types.h"
#include "libft/data/mem.h"

t_u32	ft_str_count_char(t_any_str *any_haystack, char c)
{
	t_borrowed_str *const	haystack = any_haystack;
	t_u32					count;
	t_u32					i;

	count = 0;
	i = 0;
	while (i < haystack->len)
	{
		if (haystack->c_str[i] == c)
			count++;
		i++;
	}
	return (count);
}

t_u32	ft_str_count_str(t_any_str *any_haystack, t_any_str *any_needle)
{
	t_borrowed_str *const	haystack = any_haystack;
	t_borrowed_str *const	needle = any_needle;
	t_u32					count;
	t_u32					i;

	count = 0;
	i = 0;
	while (i + needle->len < haystack->len + 1)
	{
		if (ft_mem_equal(haystack->c_str + i, needle->c_str, needle->len))
			count++;
		i++;
	}
	return (count);
}

t_u32	ft_str_count_c_str(t_any_str *any_haystack, char *needle)
{
	t_borrowed_str *const	haystack = any_haystack;
	t_u32					needle_len;
	t_u32					count;
	t_u32					i;

	needle_len = ft_c_str_len(needle);
	count = 0;
	i = 0;
	while (i + needle_len < haystack->len + 1)
	{
		if (ft_mem_equal(haystack->c_str + i, needle, needle_len))
			count++;
		i++;
	}
	return (count);
}
