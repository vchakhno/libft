/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_ljust.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchakhno <vchakhno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 04:47:55 by vchakhno          #+#    #+#             */
/*   Updated: 2023/02/28 05:36:47 by vchakhno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/str/str_internal_types.h"
#include "libft/str/str.h"
#include "libft/mem/mem.h"
#include "libft/math.h"
#include <stdlib.h>

bool	ft_str_ljust(t_allocated_str *str, size_t size, char filler)
{
	t_allocated_str	old;

	if (str->len >= size)
		return (true);
	old = *str;
	str->len = size;
	str->capacity = ft_alloc_capacity(str->len);
	if (str->capacity > old.capacity)
	{
		if (!ft_mem_malloc(&str->c_str, str->capacity))
			return (false);
		ft_mem_copy(str->c_str, old.c_str, old.len);
		free(old.c_str);
	}
	ft_mem_set(str->c_str + old.len, size - old.len, filler);
	return (true);
}
