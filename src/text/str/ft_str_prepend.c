/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_prepend.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchakhno <vchakhno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 06:56:17 by vchakhno          #+#    #+#             */
/*   Updated: 2023/01/30 10:27:01 by vchakhno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/text/str.h"
#include "libft/mem.h"
#include "libft/math.h"

bool	ft_str_prepend(t_str *str, const void *prefix_str)
{
	t_str_slice	*prefix;
	t_str		old;

	prefix = (t_str_slice *) prefix_str;
	old = *str;
	str->len += prefix->len;
	if (str->len >= str->capacity)
	{
		str->capacity = ft_math_ceil_pow2(str->len + 1);
		if (!ft_mem_malloc(&str->c_str, sizeof(char) * str->capacity))
			return (false);
	}
	ft_mem_move(str->c_str + prefix->len, old.c_str, old.len);
	if (old.c_str != str->c_str)
		ft_str_free(&old);
	ft_mem_move(str->c_str, prefix->c_str, prefix->len);
	str->c_str[str->len] = '\0';
	return (true);
}
