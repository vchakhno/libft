/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_prepend.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchakhno <vchakhno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 06:56:17 by vchakhno          #+#    #+#             */
/*   Updated: 2022/12/18 11:35:49 by vchakhno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_str.h"
#include "libft_mem.h"
#include "libft_math.h"

bool	ft_str_prepend(t_str *str, const t_str prefix)
{
	t_str	old;

	old = *str;
	str->len += prefix.len;
	if (str->len >= str->capacity)
	{
		str->capacity = ft_math_ceil_pow2(str->len + 1);
		if (!ft_mem_malloc((void **)&str->c_str, sizeof(char) * str->capacity))
			return (false);
	}
	ft_mem_move(str->c_str + prefix.len, old.c_str, old.len);
	if (old.c_str != str->c_str)
		ft_str_free(&old);
	ft_mem_move(str->c_str, prefix.c_str, prefix.len);
	str->c_str[str->len] = '\0';
	return (true);
}
