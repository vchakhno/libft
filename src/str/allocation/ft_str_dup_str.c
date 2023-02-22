/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_dup_str.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchakhno <vchakhno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 07:32:20 by vchakhno          #+#    #+#             */
/*   Updated: 2023/02/22 07:39:09 by vchakhno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/str/str_internal_types.h"
#include "libft/mem/mem.h"
#include "libft/math.h"

bool	ft_str_dup_str(t_allocated_str *dest, t_any_str *src)
{
	dest->len = src->len;
	dest->capacity = ft_alloc_capacity(dest->len);
	if (!ft_mem_malloc(&dest->c_str, dest->capacity))
		return (false);
	ft_mem_copy(dest->c_str, src->c_str, src->len);
	return (true);
}
