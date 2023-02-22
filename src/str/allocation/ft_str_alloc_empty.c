/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_alloc_empty.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchakhno <vchakhno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 07:24:06 by vchakhno          #+#    #+#             */
/*   Updated: 2023/02/22 07:27:12 by vchakhno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/str/str_internal_types.h"
#include "libft/mem/mem.h"

bool	ft_str_alloc_empty(t_allocated_str *str)
{
	if (!ft_mem_malloc(&str->c_str, 0))
		return (false);
	str->len = 0;
	str->capacity = 0;
	return (true);
}
