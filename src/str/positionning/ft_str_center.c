/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_center.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchakhno <vchakhno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 04:47:55 by vchakhno          #+#    #+#             */
/*   Updated: 2023/02/28 05:30:35 by vchakhno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/str/str_internal_types.h"
#include "libft/str/str.h"
#include "libft/mem/mem.h"
#include "libft/math.h"
#include <stdlib.h>

bool	ft_str_center(t_allocated_str *str, size_t size, char filler)
{
	t_allocated_str	old;
	size_t			margin;

	if (str->len >= size)
		return (true);
	old = *str;
	str->len = size;
	str->capacity = ft_alloc_capacity(str->len);
	if (str->capacity > old.capacity)
		if (!ft_mem_malloc(&str->c_str, str->capacity))
			return (false);
	margin = (size - old.len) / 2;
	ft_mem_move(str->c_str + margin, old.c_str, old.len);
	if (str->capacity > old.capacity)
		free(old.c_str);
	ft_mem_set(str->c_str, margin, filler);
	margin = (size - old.len + 1) / 2;
	ft_mem_set(str->c_str + str->len - margin, margin, filler);
	return (true);
}
