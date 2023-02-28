/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_select_slice.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchakhno <vchakhno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 01:02:00 by vchakhno          #+#    #+#             */
/*   Updated: 2023/02/24 01:57:45 by vchakhno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/str/str_internal_types.h"
#include "libft/mem/mem.h"

void	ft_str_select_slice(t_allocated_str *str, size_t start, size_t len)
{
	ft_mem_move(str->c_str, str->c_str + start, len);
	str->len = len;
}
