/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   append.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchakhno <vchakhno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 07:59:53 by vchakhno          #+#    #+#             */
/*   Updated: 2023/06/03 19:53:53 by vchakhno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/data/str/str.h"
#include "libft/data/mem/mem.h"

bool	ft_str_append_str(t_allocated_str *str, t_any_str *any_suffix)
{
	t_borrowed_str *const	suffix = any_suffix;

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
