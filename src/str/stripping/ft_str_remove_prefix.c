/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_remove_prefix.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchakhno <vchakhno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 06:35:00 by vchakhno          #+#    #+#             */
/*   Updated: 2023/05/03 16:32:19 by vchakhno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/str/str_internals.h"
#include "libft/fixed_types.h"
#include "libft/mem/mem.h"

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

bool	ft_str_remove_str_prefix(t_allocated_str *str, t_any_str *prefix)
{
	if (ft_str_starts_with_str((t_any_str *) str, prefix))
		ft_str_select_slice(str, prefix->len, str->len - prefix->len);
	return (true);
}
