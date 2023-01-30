/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_dup_slice.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchakhno <vchakhno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 06:56:17 by vchakhno          #+#    #+#             */
/*   Updated: 2023/01/30 07:46:42 by vchakhno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_str.h"
#include "libft_math.h"
#include "libft_mem.h"
#include "libft_c_str.h"

bool	ft_str_dup_slice(
	t_str *dest,
	const t_str src,
	size_t start, size_t len
) {
	start = ft_math_min_size_t(start, src.len);
	dest->len = ft_math_min_size_t(len, src.len - start);
	dest->capacity = ft_alloc_capacity(dest->len + 1);
	if (!ft_mem_malloc(&dest->c_str, dest->capacity))
		return (false);
	ft_c_str_ncopy(dest->c_str, src.c_str + start, dest->len);
	return (true);
}
