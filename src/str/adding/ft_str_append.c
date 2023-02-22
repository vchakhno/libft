/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_append.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchakhno <vchakhno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 07:59:53 by vchakhno          #+#    #+#             */
/*   Updated: 2023/02/22 10:29:11 by vchakhno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/str/str_internal_types.h"
#include "libft/str/str.h"
#include "libft/math.h"
#include "libft/mem/mem.h"
#include <stdlib.h>
#include <stdbool.h>

bool	ft_str_append_str(t_allocated_str *str, t_any_str *suffix)
{
	t_allocated_str	old;

	old = *str;
	str->len += suffix->len;
	str->capacity = ft_alloc_capacity(str->len);
	if (str->capacity > old.capacity)
	{
		if (!ft_mem_malloc(&str->c_str, str->capacity))
			return (false);
		ft_mem_copy(str->c_str, old.c_str, old.len);
		free(old.c_str);
		
	}
	ft_mem_copy(str->c_str + old.len, suffix->c_str, suffix->len);
	return (true);
}

bool	ft_str_append_c_str(t_allocated_str *str, char *suffix)
{
	t_borrowed_str	suffix_str;

	suffix_str = ft_c_str_borrow(suffix);
	return (ft_str_append_str(str, &suffix_str));
}
