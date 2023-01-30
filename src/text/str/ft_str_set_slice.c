/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_set_slice.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchakhno <vchakhno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 13:24:01 by vchakhno          #+#    #+#             */
/*   Updated: 2023/01/30 10:27:01 by vchakhno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/text/str.h"
#include "libft/math.h"
#include "libft/mem.h"

bool	ft_str_set_slice(t_str *str, const void *slice_str,
	size_t start, size_t len)
{
	t_str		old;
	t_str_slice	*slice;

	old = *str;
	slice = (t_str_slice *) slice_str;
	start = ft_math_min_size_t(start, str->len);
	len = ft_math_min_size_t(len, str->len - start);
	str->len += slice->len - len;
	if (str->len >= str->capacity)
	{
		str->capacity = ft_math_ceil_pow2(str->len + 1);
		if (!ft_mem_malloc(&str->c_str, sizeof(char) * str->capacity))
			return (false);
		ft_mem_copy(str->c_str, old.c_str, start);
	}
	ft_mem_move(
		str->c_str + start + slice->len,
		old.c_str + start + len,
		old.len - start - len);
	if (old.c_str != str->c_str)
		ft_str_free(&old);
	ft_mem_move(str->c_str + start, slice->c_str, slice->len);
	str->c_str[str->len] = '\0';
	return (true);
}
