/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   center.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchakhno <vchakhno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 04:47:55 by vchakhno          #+#    #+#             */
/*   Updated: 2023/05/18 07:29:58 by vchakhno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/data/str/str.h"
#include "libft/arithmetic/fixed_types.h"
#include "libft/data/mem/mem.h"
#include <stdlib.h>

bool	ft_str_center(t_allocated_str *str, t_u32 size, char filler)
{
	char	*new_c_str;
	t_u32	left_margin;
	t_u32	right_margin;

	if (str->len >= size)
		return (true);
	left_margin = (size - str->len) / 2;
	if (size > str->capacity)
	{
		if (!ft_mem_malloc(&new_c_str, size))
			return (false);
		str->capacity = size;
		ft_mem_copy(new_c_str + left_margin, str->c_str, str->len);
		free(str->c_str);
		str->c_str = new_c_str;
	}
	else
	{
		ft_mem_move(str->c_str + left_margin, str->c_str, str->len);
	}
	ft_mem_set(str->c_str, left_margin, filler);
	right_margin = (size - str->len + 1) / 2;
	ft_mem_set(str->c_str + size - right_margin, right_margin, filler);
	str->len = size;
	return (true);
}
