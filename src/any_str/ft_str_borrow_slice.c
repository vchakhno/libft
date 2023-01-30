/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_borrow_slice.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchakhno <vchakhno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 12:00:39 by vchakhno          #+#    #+#             */
/*   Updated: 2023/01/30 08:08:17 by vchakhno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_str_.h"
#include "libft_math.h"

t_str	ft_str_borrow_slice(
	t_str_slice str,
	size_t start, size_t len
) {
	t_str	slice;

	start = ft_math_min_size_t(start, str.len);
	len = ft_math_min_size_t(len, str.len - start);
	slice.c_str = str.c_str + start;
	slice.len = len;
	slice.capacity = 0;
	return (slice);
}
