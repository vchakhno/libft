/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_dup_c_str.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchakhno <vchakhno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 07:25:51 by vchakhno          #+#    #+#             */
/*   Updated: 2023/02/22 07:30:45 by vchakhno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/str/str_internal_types.h"
#include "libft/str/str.h"
#include "libft/mem/mem.h"
#include "libft/math.h"

bool	ft_str_dup_c_str(t_allocated_str *str, char *c_str)
{
	str->len = ft_c_str_len(c_str);
	str->capacity = ft_alloc_capacity(str->len);
	if (!ft_mem_malloc(&str->c_str, str->capacity))
		return (false);
	ft_mem_copy(str->c_str, c_str, str->len);
	return (true);
}

