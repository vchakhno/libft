/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_prepend.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchakhno <vchakhno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 07:59:53 by vchakhno          #+#    #+#             */
/*   Updated: 2023/05/03 23:14:35 by vchakhno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/str/str_internals.h"
#include "libft/mem/mem.h"
#include <stdlib.h>
#include <stdbool.h>

bool	ft_str_prepend_str(t_allocated_str *str, t_any_str *prefix)
{
	char	*new_c_str;

	if (str->len + prefix->len > str->capacity)
	{
		if (!ft_mem_malloc(&new_c_str, str->len + prefix->len))
			return (false);
		ft_mem_copy(new_c_str + prefix->len, str->c_str, str->len);
		free(str->c_str);
		str->c_str = new_c_str;
	}
	else
	{
		ft_mem_move(str->c_str + prefix->len, str->c_str, str->len);
	}
	ft_mem_copy(str->c_str, prefix->c_str, prefix->len);
	str->len += prefix->len;
	return (true);
}

bool	ft_str_prepend_c_str(t_allocated_str *str, char *prefix)
{
	t_borrowed_str	prefix_str;

	prefix_str = ft_c_str_borrow(prefix);
	return (ft_str_prepend_str(str, &prefix_str));
}
