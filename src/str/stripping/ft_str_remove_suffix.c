/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_remove_suffix.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchakhno <vchakhno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 06:35:00 by vchakhno          #+#    #+#             */
/*   Updated: 2023/05/03 13:39:08 by vchakhno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/str/str_internals.h"
#include "libft/mem/mem.h"

bool	ft_str_remove_c_str_suffix(t_allocated_str *str, char *suffix)
{
	if (ft_str_ends_with_c_str((t_any_str *) str, suffix))
		str->len -= ft_c_str_len(suffix);
	return (true);
}

bool	ft_str_remove_str_suffix(t_allocated_str *str, t_any_str *suffix)
{
	if (ft_str_ends_with_str((t_any_str *) str, suffix))
		str->len -= suffix->len;
	return (true);
}
