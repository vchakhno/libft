/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_append.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchakhno <vchakhno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 07:59:53 by vchakhno          #+#    #+#             */
/*   Updated: 2023/05/03 14:15:19 by vchakhno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/str/str_internals.h"
#include "libft/mem/mem.h"

bool	ft_str_append_str(t_allocated_str *str, t_any_str *suffix)
{
	if (!ft_str_reserve(str, suffix->len))
		return (false);
	ft_mem_copy(str->c_str + str->len, suffix->c_str, suffix->len);
	str->len += suffix->len;
	return (true);
}

bool	ft_str_append_c_str(t_allocated_str *str, char *suffix)
{
	t_borrowed_str	suffix_str;

	suffix_str = ft_c_str_borrow(suffix);
	return (ft_str_append_str(str, &suffix_str));
}
