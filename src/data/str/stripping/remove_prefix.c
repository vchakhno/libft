/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_prefix.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchakhno <vchakhno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 06:35:00 by vchakhno          #+#    #+#             */
/*   Updated: 2023/06/03 20:47:59 by vchakhno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/data/str.h"
#include "libft/arithmetic/fixed_types.h"
#include "libft/data/mem.h"

bool	ft_str_remove_c_str_prefix(t_allocated_str *str, char *prefix)
{
	t_u32	prefix_len;

	if (ft_str_starts_with_c_str((t_any_str *) str, prefix))
	{
		prefix_len = ft_c_str_len(prefix);
		ft_str_select_slice(str, prefix_len, str->len - prefix_len);
	}
	return (true);
}

bool	ft_str_remove_str_prefix(t_allocated_str *str, t_any_str *any_prefix)
{
	t_borrowed_str *const	prefix = any_prefix;

	if (ft_str_starts_with_str((t_any_str *) str, prefix))
		ft_str_select_slice(str, prefix->len, str->len - prefix->len);
	return (true);
}
