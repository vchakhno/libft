/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_insert.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchakhno <vchakhno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 07:59:53 by vchakhno          #+#    #+#             */
/*   Updated: 2023/02/22 10:30:28 by vchakhno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/str/str_internal_types.h"
#include "libft/str/str.h"
#include "libft/math.h"
#include "libft/mem/mem.h"
#include <stdlib.h>
#include <stdbool.h>

bool	ft_str_insert_str(t_allocated_str *str, size_t index, t_any_str *inserted)
{
	t_allocated_str	old;

	old = *str;
	str->len += inserted->len;
	str->capacity = ft_alloc_capacity(str->len);
	if (str->capacity > old.capacity)
	{
		if (!ft_mem_malloc(&str->c_str, str->capacity))
			return (false);
		ft_mem_move(str->c_str, old.c_str, index);
	}
	ft_mem_move(str->c_str + index + inserted->len,
		old.c_str + index, str->len - (index + inserted->len));
	if (str->capacity > old.capacity)
		free(old.c_str);
	ft_mem_copy(str->c_str + index, inserted->c_str, inserted->len);
	return (true);
}

bool	ft_str_insert_c_str(t_allocated_str *str, size_t index, char *inserted)
{
	t_borrowed_str	inserted_str;

	inserted_str = ft_c_str_borrow(inserted);
	return (ft_str_insert_str(str, index, &inserted_str));
}
