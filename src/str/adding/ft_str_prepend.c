/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_prepend.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchakhno <vchakhno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 07:59:53 by vchakhno          #+#    #+#             */
/*   Updated: 2023/02/22 10:30:35 by vchakhno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/str/str_internal_types.h"
#include "libft/str/str.h"
#include "libft/math.h"
#include "libft/mem/mem.h"
#include <stdlib.h>
#include <stdbool.h>

bool	ft_str_prepend_str(t_allocated_str *str, t_any_str *prefix)
{
	t_allocated_str	old;

	old = *str;
	str->len += prefix->len;
	str->capacity = ft_alloc_capacity(str->len);
	if (str->capacity > old.capacity)
		if (!ft_mem_malloc(&str->c_str, str->capacity))
			return (false);
	ft_mem_move(str->c_str + prefix->len, old.c_str, old.len);
	if (str->capacity > old.capacity) 
		free(old.c_str);
	ft_mem_copy(str->c_str, prefix->c_str, prefix->len);
	return (true);
}

bool	ft_str_prepend_c_str(t_allocated_str *str, char *prefix)
{
	t_borrowed_str	prefix_str;

	prefix_str = ft_c_str_borrow(prefix);
	return (ft_str_prepend_str(str, &prefix_str));
}
