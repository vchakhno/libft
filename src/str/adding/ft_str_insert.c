/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_insert.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchakhno <vchakhno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 07:59:53 by vchakhno          #+#    #+#             */
/*   Updated: 2023/05/03 17:10:41 by vchakhno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/str/str_internals.h"
#include "libft/fixed_types.h"
#include "libft/math.h"
#include "libft/mem/mem.h"
#include <stdlib.h>
#include <stdbool.h>

bool	ft_str_insert_str(
	t_allocated_str *str, t_u32 index, t_any_str *inserted
) {
	char	*new_c_str;

	if (str->len + inserted->len > str->capacity)
	{
		if (!ft_mem_malloc(&new_c_str, str->len + inserted->len))
			return (false);
		str->capacity = str->len + inserted->len;
		ft_mem_copy(new_c_str, str->c_str, index);
		ft_mem_copy(
			new_c_str + index + inserted->len,
			str->c_str + index,
			str->len - index);
		free(str->c_str);
		str->c_str = new_c_str;
	}
	else
	{
		ft_mem_move(
			str->c_str + index + inserted->len,
			str->c_str + index,
			str->len - index);
	}
	ft_mem_copy(str->c_str + index, inserted->c_str, inserted->len);
	str->len += inserted->len;
	return (true);
}

bool	ft_str_insert_c_str(t_allocated_str *str, t_u32 index, char *inserted)
{
	t_borrowed_str	inserted_str;

	inserted_str = ft_c_str_borrow(inserted);
	return (ft_str_insert_str(str, index, &inserted_str));
}
